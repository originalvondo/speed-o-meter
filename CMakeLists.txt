cmake_minimum_required(VERSION 3.5)
project(proj)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

FILE(GLOB_RECURSE SRC_FILES main.cpp src/*.cpp)
add_executable(program ${SRC_FILES})

target_include_directories(program PUBLIC Profiler/Includes)
add_subdirectory(Profiler)
target_link_libraries(program PUBLIC profiler)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(program PRIVATE BENCHMARK WALL)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_options(program PRIVATE -O3)
endif()
