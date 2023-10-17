//
// Created by arthur on 16/10/23.
//
#include <cstring>
#include "search.h"

template<std::size_t N>
std::pair<Employee*, std::size_t> Search::searchById(Employee (&employees)[N], int employeeId){

    std::pair<Employee*, std::size_t> employeesFound = {new Employee[N],0};

    for(const auto& employee : employees){
        if(employee->getId() == employeeId){
            std::size_t currentIndex = employeesFound.second;
            employeesFound.first[currentIndex] = employee;
            employeesFound.second++;
        }
    }

    return employeesFound;
}

template<std::size_t N>
std::pair<Employee*, std::size_t> Search::searchByName(Employee (&employees)[N], const std::string& name){

    std::pair<Employee*, std::size_t> employeesFound = {new Employee[N],0};

    for(const auto& employee: employees){
        if(employee->getName().find(name) != std::string ::npos){
            std::size_t currentIndex = employeesFound.second;
            employeesFound.first[currentIndex] = employee;
            employeesFound.second++;
        }
    }

    return employeesFound;
}


template<std::size_t N, std::size_t T>
std::pair<Employee*, std::size_t> Search::searchByName(Employee (&employees)[N], const char (&name)[T]){

    std::pair<Employee*, std::size_t> employeesFound = {new Employee[N],0};

    for(const auto& employee: employees){
        if(strstr(employee->getName().c_str(),name) != nullptr){
            std::size_t currentIndex = employeesFound.second;
            employeesFound.first[currentIndex] = employee;
            employeesFound.second++;
        }
    }

    return employeesFound;
}

template<std::size_t N>
std::pair<Employee*, std::size_t> Search::searchBySalary(Employee (&employees)[N], const float salary) {
    std::pair<Employee*, std::size_t> employeesFound = {new Employee[N],0};

    for(const auto& employee: employees){
        if(employee->getSalary() == salary){
            std::size_t currentIndex = employeesFound.second;
            employeesFound.first[currentIndex] = employee;
            employeesFound.second++;
        }
    }

    return employeesFound;
}

template<std::size_t N>
std::pair<Employee*, std::size_t> Search::searchBySalary(Employee (&employees)[N], const float& salary) {
    std::pair<Employee*, std::size_t> employeesFound = {new Employee[N],0};

    for(const auto& employee: employees){
        if(employee->getSalary() == salary){
            std::size_t currentIndex = employeesFound.second;
            employeesFound.first[currentIndex] = employee;
            employeesFound.second++;
        }
    }

    return employeesFound;
}

template<std::size_t N>
std::pair<Employee*, std::size_t> Search::searchBySalary(Employee (&employees)[N], const float&& salary) {
    std::pair<Employee*, std::size_t> employeesFound = {new Employee[N],0};

    for(const auto& employee: employees){
        if(employee->getSalary() == salary){
            std::size_t currentIndex = employeesFound.second;
            employeesFound.first[currentIndex] = employee;
            employeesFound.second++;
        }
    }

    return employeesFound;
}