//
// Created by arthur on 09/10/23.
//

#ifndef PRACTICALPROJECT_EMPLOYEE_H
#define PRACTICALPROJECT_EMPLOYEE_H

#include <string>
#include <fstream>
#include <utility>
#include <algorithm>

class Employee {
private:
    int id;
    std::string name;
    float salary;

public:
    Employee();

    Employee(int id, std::string name, float salary);

    Employee(int id, const char name[], float salary);

    [[nodiscard]] int getId() const;

    [[nodiscard]] std::string getName() const;

    [[nodiscard]] float getSalary() const;

    void save(std::ofstream& outputFile) const;

    static Employee load(std::ifstream& inputFile);

    static Employee load(std::istream& inputFile);

    template<std::size_t N>
    static void saveAll(std::ofstream &outputFile, Employee (&employees)[N]) {
        for(const auto& employee : employees){
            employee.save(outputFile);

            if(&employee != &(employees[N-1])){
                outputFile<<"\n";
            }
        }
    }

    template<std::size_t N>
    static void loadN(std::ifstream& file, Employee (&output)[N]){

        for(int i=0;i<N;i++){
            if(file){
                output[i] = load(file);
            }
        }
    }

    template<std::size_t N>
    static void loadN(std::istream& file, Employee (&output)[N]){

        for(int i=0;i<N;i++){
            if(file){
                output[i] = load(file);
            }
        }
    }
};


#endif //PRACTICALPROJECT_EMPLOYEE_H
