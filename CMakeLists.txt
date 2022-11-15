cmake_minimum_required(VERSION 3.23)
project(lab_2)

set(CMAKE_CXX_STANDARD 14)
enable_testing()

add_executable(lab_2
        main.cpp
        function.cpp
        function.h
        Google_tests/test.cpp)
add_subdirectory(Google_tests)
