//

#include "Employee.h"

Employee::Employee():id{},name{},salary{}{}

Employee::Employee(int id, std::string name, float salary): id(id), name(std::move(name)), salary(salary){}

//
// Created by arthur on 09/10/23.
Employee::Employee(int id, const char *name, float salary):id(id),name(name), salary(salary){}

int Employee::getId() const {
    return this->id;
}

std::string Employee::getName() const {
    return this->name;
}

float Employee::getSalary() const {
    return this->salary;
}

void Employee::save(std::ofstream &outputFile) const {

    outputFile<<id;

    outputFile<<'\t';


    outputFile<<name;

    outputFile<<'\t';


    outputFile<<salary;
}

Employee Employee::load(std::ifstream &inputFile) {
    int id;
    std::string name;
    float salary;

    if(inputFile>>id && inputFile>>name && inputFile>>salary){
        return {id, name, salary};
    }

    return {0, "", 0.0};
}

Employee Employee::load(std::istream &inputFile) {
    int id;
    std::string name;
    float salary;

    if(inputFile>>id && inputFile>>name && inputFile>>salary){
        return {id, name, salary};
    }

    return {0, "", 0.0};
}