cmake_minimum_required(VERSION 3.23)
project(calc)

set(CMAKE_CXX_STANDARD 14)

add_executable(calc main.cpp calc_lib.cpp calc_lib.h)
