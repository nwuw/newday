cmake_minimum_required(VERSION 3.23)
project(basic_c C)

set(CMAKE_C_STANDARD 99)

add_executable(
        basic_c
        main.c
        utils/utils.h
        utils/utils.c
)
