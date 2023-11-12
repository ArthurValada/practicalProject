//
// Created by arthur on 06/11/23.
//

#ifndef PRACTICALPROJECT_ACTIONS_H
#define PRACTICALPROJECT_ACTIONS_H

#include <functional>
#include "../DynamicVector/DynamicVector.h"
#include "../Models/PlantModel/PlantModel.h"

namespace Actions{

    void _goAhead(PlantModel* plant, const std::function<void(PlantModel*)>& pFunction);

    [[maybe_unused]] DynamicVector<PlantModel> loadFromCsv(std::ifstream& file);
    [[maybe_unused]] DynamicVector<PlantModel> loadFromCsv(const std::filesystem::path&);


    [[maybe_unused]] void saveInCsv(const DynamicVector<PlantModel>& plants, std::ofstream& file);

    [[maybe_unused]] void saveInCsv(const DynamicVector<PlantModel>& plants,const std::filesystem::path& filePath);

    [[maybe_unused]] PlantModel* findById(const DynamicVector<PlantModel>& plants, int id);


    [[maybe_unused]] PlantModel* findByName(const DynamicVector<PlantModel>& plants, const std::string& name);

    [[maybe_unused]] void alterName(PlantModel* plant, const std::string& name);

    [[maybe_unused]] PlantModel* findByDescription(const DynamicVector<PlantModel>& plants, const std::string& description);

    [[maybe_unused]] void alterDescription(PlantModel* plant, const std::string& description);

    [[maybe_unused]] PlantModel* findByRegionOfOrigin(const DynamicVector<PlantModel>& plants, const std::string& regionOfOrigin);

    [[maybe_unused]] void alterRegionOfOrigin(PlantModel* plant, const std::string& regionOfOrigin);

    [[maybe_unused]] PlantModel* findByFamily(const DynamicVector<PlantModel>& plants, const std::string& family);

    [[maybe_unused]] void alterFamily(PlantModel* plant, const std::string& family);

    [[maybe_unused]] PlantModel* findByScientificName(const DynamicVector<PlantModel>& plants, const std::string& scientificName);

    [[maybe_unused]] void alterScientificName(PlantModel* plant, const std::string& scientificName);
}

#endif //PRACTICALPROJECT_ACTIONS_H
