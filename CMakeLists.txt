cmake_minimum_required(VERSION 3.26)
project(practicalProject)

set(CMAKE_CXX_STANDARD 23)

add_executable(
        practicalProject main.cpp

        DynamicVector/DynamicVector.h

        Models/ContentModel.h

        Models/PlantModel/PlantModel.h
        Models/PlantModel/PlantModel.cpp

        Actions/Actions.h
        Actions/Actions.cpp

        CliInterface/Cli.h
        CliInterface/Cli.cpp

        Helpers/Helpers.h
        Helpers/Helpers.cpp
)

target_compile_options(practicalProject PRIVATE -Wl,--stack,10000000)
