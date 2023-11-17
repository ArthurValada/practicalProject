//
// Created by arthur on 26/10/23.
//

#include "PlantModel.h"

#include <utility>

PlantModel::PlantModel(
        int id,
        std::string name,
        std::string family,
        std::string regionOfOrigin,
        std::string scientificName,
        std::string description
) :
        _id(id),
        _name(std::move(name)),
        _family(std::move(family)),
        _scientificName(std::move(scientificName)),
        _regionOfOrigin(std::move(regionOfOrigin)),
        _description(std::move(description)) {}

PlantModel PlantModel::loadFromCsv(std::ifstream &file) {

    int id;
    std::string name;
    std::string scientificName;
    std::string family;
    std::string regionOfOrigin;
    std::string description;

    char trash;

    if (file >> id) {
        file >> trash;

        std::getline(file, name, ',');

        file>>trash;
        std::getline(file, scientificName, '\'');
        file>>trash;

        std::getline(file, family, ',');
        file >> trash;

        std::getline(file, regionOfOrigin, '\'');
        file>>trash;

        file>>trash;
        std::getline(file, description, '\'');

        file.ignore();
        return {id, name, family, regionOfOrigin, scientificName, description};
    }
    return {};
}

void PlantModel::saveInCsv(std::ofstream &file) {
    if (file.good()) {
        file << _id << ",\'" << _name << "\'," << _family << ",\'" << _regionOfOrigin << "\'," << _scientificName << "\',\'"
             << _description << "\'" << std::endl;
    }
}

int PlantModel::getId() const {
    return this->_id;
}

std::string PlantModel::getName() const {
    return this->_name;
}

std::string PlantModel::getFamily() const {
    return this->_family;
}

std::string PlantModel::getRegionOfOrigin() const {
    return this->_regionOfOrigin;
}

std::string PlantModel::getScientificName() const {
    return this->_scientificName;
}

std::string PlantModel::getDescription() const {
    return this->_description;
}

bool PlantModel::operator==(const PlantModel& other) const {
    return this->_id == other._id and this->_name == other._name and this->_description == other._description and
           this->_scientificName == other._scientificName and this->_regionOfOrigin == other._regionOfOrigin;
}

void PlantModel::setName(std::string newName) {
    this->_name = std::move(newName);
}

void PlantModel::setFamily(std::string family) {
    this->_family = std::move(family);
}

void PlantModel::setRegionOfOrigin(std::string regionOfOrigin) {
    this->_regionOfOrigin = std::move(regionOfOrigin);
}

void PlantModel::setScientificName(std::string scientificName) {
    this->_scientificName = std::move(scientificName);
}

void PlantModel::setDescription(std::string description) {
    this->_description = std::move(description);
}

void PlantModel::show() const {
    std::cout<<"Id:"<<_id<<std::endl;
    std::cout<<"Nome:"<<_name<<std::endl;
    std::cout<<"Descrição:"<<_description<<std::endl;
    std::cout<<"Nome scientífico:"<<_scientificName<<std::endl;
    std::cout<<"Família:"<<_family<<std::endl;
    std::cout<<"Região de origem:"<<_regionOfOrigin<<std::endl;
}
