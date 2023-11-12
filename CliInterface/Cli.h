//
// Created by arthur on 06/11/23.
//

#ifndef PRACTICALPROJECT_CLI_H
#define PRACTICALPROJECT_CLI_H

#include <initializer_list>
#include <utility>
#include <string>
#include <functional>
#include <iostream>
#include <cstring>
#include <map>

#include "../Actions/Actions.h"

namespace Cli{
    [[maybe_unused]] DynamicVector<PlantModel> load();

    [[maybe_unused]] void save(const DynamicVector<PlantModel>& plants);

    [[maybe_unused]] PlantModel* findById(const DynamicVector<PlantModel> &plants);

    [[maybe_unused]] PlantModel* findByName(const DynamicVector<PlantModel>& plants);

    [[maybe_unused]] PlantModel* findByDescription(const DynamicVector<PlantModel>& plants);

    [[maybe_unused]] PlantModel* findByScientificName(const DynamicVector<PlantModel>& plants);

    [[maybe_unused]] PlantModel* findByFamily(const DynamicVector<PlantModel>& plants);

    [[maybe_unused]] PlantModel* findByRegionOfOrigin(const DynamicVector<PlantModel>& plants);

    PlantModel* find(const DynamicVector<PlantModel>& plants);


    [[maybe_unused]] void alterPlantName(const DynamicVector<PlantModel>& plants);

    [[maybe_unused]] void alterPlantDescription(const DynamicVector<PlantModel>& plants);

    [[maybe_unused]] void alterPlantScientificName(const DynamicVector<PlantModel>& plants);

    [[maybe_unused]] void alterPlantFamily(const DynamicVector<PlantModel>& plants);

    [[maybe_unused]] void alterPlantRegionOfOrigin(const DynamicVector<PlantModel>& plants);

    [[maybe_unused]] void alter(const DynamicVector<PlantModel>& plants);


    [[maybe_unused]] void menu();
}

#endif //PRACTICALPROJECT_CLI_H
