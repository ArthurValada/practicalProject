cmake_minimum_required(VERSION 3.26)
project(practicalProject)

set(CMAKE_CXX_STANDARD 23)

add_executable(
        practicalProject main.cpp
        DynamicVector/DynamicVector.h
)