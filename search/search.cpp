//
// Created by arthur on 09/10/23.
//

#include "search.h"
#include "../DynamicArray/DynamicArray.h"

template<std::size_t N>
Employee *search::searchById(Employee employees[N], int employeeId) {

    for(Employee& employee : employees){
        if(employee.getId()==employeeId){
            return &employee;
        }
    }

    return nullptr;
}


template<std::size_t N>
Employee *search::searchByName(Employee employees[N], const std::string& name) {

    for(Employee& employee : employees){
        if(employee.getName().find(name)!=std::string::npos){
            return &employee;
        }
    }

    return nullptr;
}

//template<std::size_t N>
//Employee *search::searchBySalary(Employee employees[N], const float salary)  {
//    return Employee();
//}