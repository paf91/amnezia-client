cmake_minimum_required(VERSION 3.25.0 FATAL_ERROR)

if(NOT WIN32)
    message(STATUS "Skipping WindowsFirewall tests: only available on Windows")
    return()
endif()

add_executable(windowsfirewall_sublayer_result_tests
    windows/windowsfirewall_sublayer_result_tests.cpp
)

target_include_directories(windowsfirewall_sublayer_result_tests PRIVATE
    ${CMAKE_SOURCE_DIR}
)

add_test(
    NAME windowsfirewall_sublayer_result_tests
    COMMAND windowsfirewall_sublayer_result_tests
)
