#
# Copyright (C) 2017-2020 Intel Corporation
#
# SPDX-License-Identifier: MIT
#

set(IGDRCL_SRCS_tests_helpers
    ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
    ${CMAKE_CURRENT_SOURCE_DIR}/array_count_tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/base_object_tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basic_math_tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/bit_helpers_tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cl_helper_tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cmd_buffer_validator.h
    ${CMAKE_CURRENT_SOURCE_DIR}/cmd_buffer_validator_tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/debug_helpers_tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/deferred_deleter_helpers_tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dirty_state_helpers_tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dispatch_info_builder_tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dispatch_info_tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/extendable_enum_tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/flush_stamp_tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/get_gpgpu_engines_tests.inl
    ${CMAKE_CURRENT_SOURCE_DIR}/get_info_tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/get_info_status_mapper_tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/gtest_helpers.h
    ${CMAKE_CURRENT_SOURCE_DIR}/hardware_commands_helper_tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/hardware_commands_helper_tests.h
    ${CMAKE_CURRENT_SOURCE_DIR}/heap_assigner_ocl_tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/hw_helper_default_tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/hw_helper_tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/hw_helper_tests.h
    ${CMAKE_CURRENT_SOURCE_DIR}/kernel_filename_helper.h
    ${CMAKE_CURRENT_SOURCE_DIR}/kmd_notify_tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/memory_management_tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/memory_properties_helpers_tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/mipmap_tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/per_thread_data_tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ptr_math_tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/queue_helpers_tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/raii_hw_helper.h
    ${CMAKE_CURRENT_SOURCE_DIR}/sampler_helpers_tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/task_information_tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test_debug_variables.inl
    ${CMAKE_CURRENT_SOURCE_DIR}/timestamp_packet_tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/transfer_properties_tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/uint16_sse4_tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ult_limits.h
    ${CMAKE_CURRENT_SOURCE_DIR}/unit_test_helper.h
    ${CMAKE_CURRENT_SOURCE_DIR}/unit_test_helper.inl
    ${CMAKE_CURRENT_SOURCE_DIR}/validator_tests.cpp
    ${NEO_SHARED_TEST_DIRECTORY}/unit_test/helpers/aligned_memory_tests.cpp
    ${NEO_SHARED_TEST_DIRECTORY}/unit_test/helpers/debug_manager_state_restore.h
)

get_property(NEO_CORE_PREAMBLE_TESTS GLOBAL PROPERTY NEO_CORE_PREAMBLE_TESTS)

list(APPEND IGDRCL_SRCS_tests_helpers
     ${NEO_CORE_PREAMBLE_TESTS}
)

target_sources(igdrcl_tests PRIVATE ${IGDRCL_SRCS_tests_helpers})
add_subdirectories()
