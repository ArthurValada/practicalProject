cmake_minimum_required(VERSION 3.26)
project(practicalProject)

set(CMAKE_CXX_STANDARD 23)

add_executable(
        practicalProject main.cpp
        search/search.h
        search/search.cpp
        Employee/Employee.h
        Employee/Employee.cpp
        fileSystem/fileSystem.h
        fileSystem/fileSystem.cpp
        fileStream/FileStream.h
        fileStream/FileStream.cpp
        employeeCLI/EmployeeCli.h
        employeeCLI/EmployeeCli.cpp
)
