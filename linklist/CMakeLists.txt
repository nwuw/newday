cmake_minimum_required(VERSION 3.23.2)
project(linklist C)

set(CMAKE_C_STANDARD 99)

add_executable(
    linklist 
    main.c 
    linklist.h 
    linklist.c 
    utils.h 
    utils.c
)
