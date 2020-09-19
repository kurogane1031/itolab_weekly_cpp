cmake_minimum_required(VERSION 3.10)
project(week3)
set (CMAKE_CXX_STANDARD 11)
SET(CMAKE_EXPORT_COMPILE_COMMANDS "ON")

include_directories(include)

add_executable(copy_demonstration src/copy_demonstration.cpp)
