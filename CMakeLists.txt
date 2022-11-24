cmake_minimum_required(VERSION 3.16)
project(calc)

set(This calc)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

set(Header calc_lib.h)
set(Sources calc_lib.cpp)

add_library(calc_lib.h STATIC ${Sources} ${Headers})

add_subdirectory(GoogleTest)

add_executable(calc main.cpp calc_lib.cpp calc_lib.h)
