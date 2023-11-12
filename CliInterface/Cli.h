//
// Created by arthur on 06/11/23.
//

#ifndef PRACTICALPROJECT_COMMANDS_H
#define PRACTICALPROJECT_COMMANDS_H

#include <initializer_list>
#include <utility>
#include <string>
#include <functional>
#include <iostream>

namespace Commands{
    void menu(int argc, int* argv[]){

        bool isContentLoaded = false;

        std::pair<std::string, std::function<void(char*)>> options[] = {
                {
                    "load",
                    [](char* _) {

                    }
                }
        };



    }
}

#endif //PRACTICALPROJECT_COMMANDS_H
