
cmake_minimum_required(VERSION 3.16)

project(NexusCore VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(nexuscore_lib
    src/Task.cpp
    src/TaskManager.cpp
    src/TaskStorage.cpp
)

target_include_directories(nexuscore_lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(nexuscore
    src/main.cpp
)

target_link_libraries(nexuscore
    PRIVATE nexuscore_lib
)

enable_testing()

add_executable(nexuscore_tests
    tests/test_taskmanager.cpp
)

target_link_libraries(nexuscore_tests
    PRIVATE nexuscore_lib
)

add_test(
    NAME NexusCoreTests
    COMMAND nexuscore_tests
)

set_target_properties(nexuscore PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
)
