/*
 * Copyright (C) 2018-2020 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#pragma once
#include "shared/source/memory_manager/memory_banks.h"
#include "shared/source/memory_manager/physical_address_allocator.h"

#include "opencl/source/command_stream/command_stream_receiver_simulated_common_hw.h"

namespace NEO {
class GraphicsAllocation;
template <typename GfxFamily>
class CommandStreamReceiverSimulatedHw : public CommandStreamReceiverSimulatedCommonHw<GfxFamily> {
  protected:
    using CommandStreamReceiverSimulatedCommonHw<GfxFamily>::CommandStreamReceiverSimulatedCommonHw;
    using CommandStreamReceiverSimulatedCommonHw<GfxFamily>::osContext;
    using CommandStreamReceiverSimulatedCommonHw<GfxFamily>::getDeviceIndex;

  public:
    uint32_t getMemoryBank(GraphicsAllocation *allocation) const {
        return MemoryBanks::getBank(getDeviceIndex());
    }
    int getAddressSpace(int hint) {
        bool traceLocalAllowed = false;
        switch (hint) {
        case AubMemDump::DataTypeHintValues::TraceLogicalRingContextRcs:
        case AubMemDump::DataTypeHintValues::TraceLogicalRingContextCcs:
        case AubMemDump::DataTypeHintValues::TraceLogicalRingContextBcs:
        case AubMemDump::DataTypeHintValues::TraceLogicalRingContextVcs:
        case AubMemDump::DataTypeHintValues::TraceLogicalRingContextVecs:
        case AubMemDump::DataTypeHintValues::TraceCommandBuffer:
            traceLocalAllowed = true;
            break;
        default:
            break;
        }
        if ((traceLocalAllowed && this->localMemoryEnabled) || DebugManager.flags.AUBDumpForceAllToLocalMemory.get()) {
            return AubMemDump::AddressSpaceValues::TraceLocal;
        }
        return AubMemDump::AddressSpaceValues::TraceNonlocal;
    }
    PhysicalAddressAllocator *createPhysicalAddressAllocator(const HardwareInfo *hwInfo) {
        return new PhysicalAddressAllocator();
    }
    void writeMemoryWithAubManager(GraphicsAllocation &graphicsAllocation) override {
        uint64_t gpuAddress;
        void *cpuAddress;
        size_t size;
        this->getParametersForWriteMemory(graphicsAllocation, gpuAddress, cpuAddress, size);
        int hint = graphicsAllocation.getAllocationType() == GraphicsAllocation::AllocationType::COMMAND_BUFFER
                       ? AubMemDump::DataTypeHintValues::TraceBatchBuffer
                       : AubMemDump::DataTypeHintValues::TraceNotype;

        auto pageSize = graphicsAllocation.getUsedPageSize();
        this->aubManager->writeMemory(gpuAddress, cpuAddress, size, this->getMemoryBank(&graphicsAllocation), hint, pageSize);
    }

    void setAubWritable(bool writable, GraphicsAllocation &graphicsAllocation) override {
        graphicsAllocation.setAubWritable(writable, getMemoryBank(&graphicsAllocation));
    }
    bool isAubWritable(GraphicsAllocation &graphicsAllocation) const override {
        return graphicsAllocation.isAubWritable(getMemoryBank(&graphicsAllocation));
    }
    void setTbxWritable(bool writable, GraphicsAllocation &graphicsAllocation) override {
        graphicsAllocation.setTbxWritable(writable, getMemoryBank(&graphicsAllocation));
    }
    bool isTbxWritable(GraphicsAllocation &graphicsAllocation) const override {
        return graphicsAllocation.isTbxWritable(getMemoryBank(&graphicsAllocation));
    }
};
} // namespace NEO
