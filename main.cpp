#include <iostream>
#include <fstream>

#include "./search/search.h"
#include "./Employee/Employee.h"

int main(int argc, char* argv[]) {

    const char* fileName = "./output.txt";

    std::ofstream outputFile(fileName);

        Employee employees[] = {
                Employee(1, "Arthur", 20.0),
                Employee(2,"Felipe", 100.0)
        };

        Employee::saveAll(outputFile, employees);

    outputFile.close();


    std::ifstream inputFile(fileName);



    inputFile.close();



    return 0;
}
