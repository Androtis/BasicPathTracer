cmake_minimum_required(VERSION 3.27)
project(BasicPathTracer)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)
set(CMAKE_CXX_STANDARD 23)
file(GLOB SOURCES *.h)

add_executable(main_file "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
target_include_directories(main_file PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
