//
// Created by arthur on 26/10/23.
//

#ifndef PRACTICALPROJECT_PLANTMODEL_H
#define PRACTICALPROJECT_PLANTMODEL_H

#include <utility>
#include <fstream>
#include <iostream>

#include "../ContentModel.h"

class PlantModel : ContentModel<PlantModel> {

private:
    int _id{};
    std::string _name;
    std::string _family;
    std::string _scientificName;
    std::string _regionOfOrigin;
    std::string _description;

public:

    PlantModel(int id, std::string name, std::string family, std::string regionOfOrigin, std::string scientificName,
               std::string description);

    PlantModel() = default;


    static PlantModel loadFromCsv(std::ifstream &file);
    void saveInCsv(std::ofstream &file) override ;

    static PlantModel loadFromBinary(std::ifstream &file);
    void saveInBinary(std::ofstream &file) const ;


    [[nodiscard]] int getId() const;
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] std::string getFamily() const;
    [[nodiscard]] std::string getRegionOfOrigin() const;
    [[nodiscard]] std::string getScientificName() const;
    [[nodiscard]] std::string getDescription() const;


    void setName(std::string newName);
    void setFamily(std::string family);
    void setRegionOfOrigin(std::string regionOfOrigin);
    void setScientificName(std::string scientificName);
    void setDescription(std::string description);

    bool operator==(const PlantModel& other) const;
    void show() const;

};

#endif //PRACTICALPROJECT_PLANTMODEL_H
