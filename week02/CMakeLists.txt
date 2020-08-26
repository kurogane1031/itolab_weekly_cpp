cmake_minimum_required(VERSION 3.10)
project(demo)

# 6. compiler flags
SET(CMAKE_CXX_COMPILER "/usr/bin/clang++-10")
SET(CMAKE_CXX_FLAGS "-g -Wall -Wno-conversion -Wextra -Wpedantic -ftime-trace")
SET(CMAKE_EXPORT_COMPILE_COMMANDS "ON")

# 4
#find_package(
#  )

# 2. header file directory
# include_directories(
# add list of include directory here, space separated
# just folder name is enough
#  )

# 3. using GLOB and wild card
#file(GLOB NAME "src/*.cpp")

# 1.
add_executable(
  # executable name
  demo
  # list of source file (.cpp, .cxx)
  main.cpp
  )

# 5. link libraries
# target_link_libraries(
# executable name
# list of libraries, space separated
#  )
