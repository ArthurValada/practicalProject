//
// Created by arthur on 09/10/23.
//

#ifndef PRATICALPROJECT_SEARCH_H
#define PRATICALPROJECT_SEARCH_H

#pragma once
#include "../Employee/Employee.h"
#include <chrono>

namespace search{

    template<std::size_t N>
    Employee *searchById(Employee employees[N], int employeeId);

    template<std::size_t N>
    Employee *searchByName(Employee employees[N], const std::string& name);

    template<std::size_t N>
    Employee *searchByAge(Employee employees[N], auto date = std::chrono::system_clock::now());

    template<std::size_t N>
    Employee *searchBySalary(Employee employees[N], float salary) ;

    template<std::size_t N>
    Employee *searchBySalary(Employee employees[N], const float& salary);

    template<std::size_t N>
    Employee *searchBySalary(Employee employees[N], const float&& salary);

}

#endif //PRATICALPROJECT_SEARCH_H
