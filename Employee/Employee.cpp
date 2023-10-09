//
// Created by arthur on 09/10/23.
//

#pragma once
#include "Employee.h"
#include <utility>

Employee::Employee(int id, std::string name, float salary): id(id), name(std::move(name)), salary(salary){}

int Employee::getId() const {
    return this->id;
}

std::string Employee::getName() const {
    return this->name;
}

float Employee::getSalary() const {
    return this->salary;
}
