//
// Created by arthur on 16/10/23.
//
#include <iterator>

#include "FileStream.h"

void FileStream::createEmployee(std::istream& file, int number) {

    file.unsetf(std::ios_base::skipws);

    unsigned line_count = std::count(std::istream_iterator<char>(file),std::istream_iterator<char>(),'\n') +1;
    Employee employees[3];

    Employee::loadN(file, employees);

}