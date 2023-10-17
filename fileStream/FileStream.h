//
// Created by arthur on 16/10/23.
//

#ifndef PRACTICALPROJECT_FILESTREAM_H
#define PRACTICALPROJECT_FILESTREAM_H

#include <fstream>

#include "../Employee/Employee.h"
#include "../employeeCLI/EmployeeCli.h"

namespace FileStream{
    void createEmployee(std::istream &file, int number = 1);

    void deleteEmployee(std::istream& file, Employee employeeData);

    void alterEmployee(std::istream& file, Employee employeeData);
}

#endif //PRACTICALPROJECT_FILESTREAM_H
