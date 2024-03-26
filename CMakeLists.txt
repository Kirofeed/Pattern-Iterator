cmake_minimum_required(VERSION 3.27)
project(RGR2)

set(CMAKE_CXX_STANDARD 17)

add_executable(RGR2 main.cpp
        KSet.h
        KSet.cpp
        iter.cpp)
