cmake_minimum_required(VERSION 2.8)

add_subdirectory(vendor/googletest)
include_directories(header)
file(GLOB SOURCES src/*.cpp)
file(GLOB TEST_SOURCES unit_tests/unit_test.cpp src/Command.cpp src/CommandLine.cpp src/Connector.cpp src/AndOrSemicolon.cpp)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ./)

add_executable(rshell
    ${SOURCES}
)

add_executable(test
    ${TEST_SOURCES}
)

target_link_libraries(test gtest)
target_compile_definitions(test PRIVATE gtest_disable_pthreads=ON)