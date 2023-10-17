//
// Created by arthur on 16/10/23.
//
#include <iostream>

#include "EmployeeCli.h"

Employee EmployeeCLI::newEmployee() {

    int id;
    std::string name;
    float salary;

    std::cout<<"Informe o Id do funcionário:";
    std::cin>>id;

    std::cout<<"Informe o nome do funcionário:";
    std::cin>>name;

    std::cout<<"Informe o salário do funcionário:";
    std::cin>>salary;

    return {id, name, salary};
}