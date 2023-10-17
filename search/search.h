//
// Created by arthur on 09/10/23.
//

#ifndef PRACTICALPROJECT_SEARCH_H
#define PRACTICALPROJECT_SEARCH_H

#include "../Employee/Employee.h"
#include <iostream>
#include <chrono>

namespace Search{

    template<std::size_t N>
    std::pair<Employee*, std::size_t> searchById(Employee (&employees)[N], int employeeId);

    template<std::size_t N>
    std::pair<Employee*, std::size_t> searchByName(Employee (&employees)[N], const std::string& name);

    template<std::size_t N, std::size_t T>
    std::pair<Employee*, std::size_t> searchByName(Employee (&employees)[N], const char name[T]);

    template<std::size_t N>
    std::pair<Employee*, std::size_t> searchBySalary(Employee (&employees)[N], float salary) ;

    template<std::size_t N>
    std::pair<Employee*, std::size_t> searchBySalary(Employee (&employees)[N], const float& salary);

    template<std::size_t N>
    std::pair<Employee*, std::size_t> searchBySalary(Employee (&employees)[N], const float&& salary);

}

#endif //PRACTICALPROJECT_SEARCH_H
