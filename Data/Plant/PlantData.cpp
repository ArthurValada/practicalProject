//
// Created by arthur on 13/11/23.
//
#include "./PlantData.h"

PlantData::PlantData(int id, const std::string &name, const std::string &family, const std::string &scientificName,
                     const std::string &regionOfOrigin, const std::string &description) {
    this->id = id;
    this->name = name.c_str();
    this->family = family.c_str();
    this->scientificName = scientificName.c_str();
    this->regionOfOrigin = regionOfOrigin.c_str();
    this->description = description.c_str();
}
