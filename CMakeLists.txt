cmake_minimum_required(VERSION 3.30)
project(IKM)

set(CMAKE_CXX_STANDARD 26)

add_executable(IKM main.cpp
        Functions.h
        Data_Handler.cpp
        Data_Handler.h)
