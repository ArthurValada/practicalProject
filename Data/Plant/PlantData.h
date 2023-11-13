//
// Created by arthur on 13/11/23.
//

#ifndef PRACTICALPROJECT_PLANTDATA_H
#define PRACTICALPROJECT_PLANTDATA_H

#include <string>

struct PlantData{
    int id{};
    const char* name{};
    const char* family{};
    const char* scientificName{};
    const char* regionOfOrigin{};
    const char* description{};

    PlantData() = default;

    PlantData(int id, const std::string& name, const std::string& family, const std::string& scientificName,const std::string& regionOfOrigin, const std::string& description);
};

#endif //PRACTICALPROJECT_PLANTDATA_H
