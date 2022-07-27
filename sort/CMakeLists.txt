cmake_minimum_required(VERSION 3.23.2)
project(sort C)

set(CMAKE_C_STANDARD 99)

add_executable(
    sort
    main.c
    utils.h
    utils.c
    sort.h
    sort.c
)