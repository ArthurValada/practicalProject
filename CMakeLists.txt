cmake_minimum_required(VERSION 3.26)
project(praticalProject)

set(CMAKE_CXX_STANDARD 23)

add_executable(praticalProject main.cpp
        search/search.cpp
        search/search.h
        Employee/Employee.cpp
        Employee/Employee.h
        DynamicArray/DynamicArray.cpp
        DynamicArray/DynamicArray.h)
