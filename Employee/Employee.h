//
// Created by arthur on 09/10/23.
//

#ifndef PRATICALPROJECT_EMPLOYEE_H
#define PRATICALPROJECT_EMPLOYEE_H

#pragma once
#include "string"

class Employee {
private:
    int id;
    std::string name;
    float salary;

public:
    Employee(int id, std::string name, float salary);

    [[nodiscard]] int getId() const;

    [[nodiscard]] std::string getName() const;

    [[nodiscard]] float getSalary() const;

};


#endif //PRATICALPROJECT_EMPLOYEE_H
