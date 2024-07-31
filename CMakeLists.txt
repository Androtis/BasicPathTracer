cmake_minimum_required(VERSION 3.27)
project(BasicPathTracer)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)
add_executable(main_file "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
