cmake_minimum_required(VERSION 3.22)
project (unit_test)

set(CMAKE_CXX_STANDARD 14)
include_directories(src)
add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(lib/googletest)
#add_executable(unit_test main.cpp)
