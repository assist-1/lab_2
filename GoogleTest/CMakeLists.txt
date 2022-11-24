cmake_minimum_required(VERSION 3.16)

set(This GoogleTest)

set(Sources test.cpp)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
        gtest
        gtest_main
        pthread
        calc_lib.h)

add_test(
        NAME ${This}
        COMMAND ${This}
)