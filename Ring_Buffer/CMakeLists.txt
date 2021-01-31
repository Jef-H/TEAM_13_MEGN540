cmake_minimum_required(VERSION 3.17)
project(Ring_Buffer C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Ring_Buffer
        main.c
        Ring_Buffer.c
        Ring_Buffer.h)
