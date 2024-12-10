cmake_minimum_required(VERSION 3.29)
project(C_Data_Structures C)

set(CMAKE_C_STANDARD 11)

add_executable(C_Data_Structures main.c
        Hashmap/h_t.h
        Hashmap/h_t.c)
