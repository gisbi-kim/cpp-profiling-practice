cmake_minimum_required(VERSION 3.10)
project(my_program)

# Set compiler flags
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

# Find gperftools
find_library(GPERFTOOLS_LIBRARIES NAMES profiler)

# Add the executable
add_executable(my_program my_program.cpp)

# Link with gperftools
target_link_libraries(my_program ${GPERFTOOLS_LIBRARIES})
