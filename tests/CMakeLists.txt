cmake_minimum_required(VERSION 3.25.0 FATAL_ERROR)

add_executable(interfaceconfig_json_tests
    common/interfaceconfig_json_tests.cpp
    ${CMAKE_SOURCE_DIR}/client/daemon/interfaceconfig.cpp
    ${CMAKE_SOURCE_DIR}/client/mozilla/shared/ipaddress.cpp
)

target_include_directories(interfaceconfig_json_tests PRIVATE
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/client/mozilla/shared
)

target_link_libraries(interfaceconfig_json_tests PRIVATE
    Qt6::Core
    Qt6::Network
)

add_test(
    NAME interfaceconfig_json_tests
    COMMAND interfaceconfig_json_tests
)

if(NOT WIN32)
    message(STATUS "Skipping Windows-only split tunnel tests")
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

add_executable(windowssplittunnel_config_utils_tests
    windows/windowssplittunnel_config_utils_tests.cpp
)

target_include_directories(windowssplittunnel_config_utils_tests PRIVATE
    ${CMAKE_SOURCE_DIR}
)

add_test(
    NAME windowssplittunnel_config_utils_tests
    COMMAND windowssplittunnel_config_utils_tests
)
