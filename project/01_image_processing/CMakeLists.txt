cmake_minimum_required(VERSION 3.18)
project(image_processing)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")
SET(CMAKE_CXX_FLAGS "-g -Wall -Wno-conversion -Wextra -Wpedantic -O2")

add_executable(run src/image_reader.cpp)
target_link_libraries(run)
