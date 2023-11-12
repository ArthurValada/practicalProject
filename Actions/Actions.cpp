//
// Created by arthur on 06/11/23.
//

#include "Actions.h"

void Actions::_goAhead(PlantModel *plant, const std::function<void(PlantModel *)> &pFunction) {
    if(plant != nullptr){
        pFunction(plant);
    }
    else{
        throw std::invalid_argument("The plant(: PlantModel*) should not be null.");
    }
}

DynamicVector<PlantModel> Actions::load(std::ifstream &file) {
    DynamicVector<PlantModel> plants = DynamicVector<PlantModel>();

    bool shouldStop = false;
    while(not shouldStop){
        PlantModel plant = PlantModel::load(file);
        if(plant != PlantModel()){
            plants.push_back(plant);
        }
        else{
            shouldStop = true;
        }
    }

    return plants;
}

void Actions::save(const DynamicVector<PlantModel> &plants, std::ofstream &file) {
    if(file.good()){
        for(auto element : plants){
            element.save(file);
        }
    }
}

PlantModel *Actions::findById(const DynamicVector<PlantModel> &plants, int id) {
    for(auto& element: plants){
        if(element.getId() == id){
            return &element;
        }
    }
    return nullptr;
}

PlantModel *Actions::findByName(const DynamicVector<PlantModel> &plants, const std::string &name) {
    for(auto& element : plants){
        if(element.getName() == name){
            return &element;
        }
    }
    return nullptr;
}

void Actions::alterName(PlantModel *plant, const std::string &name) {
    _goAhead(plant,[&name](PlantModel* plant){
        plant->setName(name);
    });
}

PlantModel *Actions::findByDescription(const DynamicVector<PlantModel> &plants, const std::string &description) {
    for(auto& element : plants){
        if(element.getDescription() == description){
            return &element;
        }
    }

    return nullptr;
}

void Actions::alterDescription(PlantModel *plant, const std::string &description) {
    _goAhead(plant,[&description](PlantModel* plant){
        plant->setName(description);
    });
}

PlantModel *Actions::findByRegionOfOrigin(const DynamicVector<PlantModel> &plants, const std::string &regionOfOrigin) {
    for(auto& element: plants){
        if(element.getRegionOfOrigin() == regionOfOrigin){
            return &element;
        }
    }

    return nullptr;
}

void Actions::alterRegionOfOrigin(PlantModel *plant, const std::string &regionOfOrigin) {
    _goAhead(plant,[&regionOfOrigin](PlantModel* plant){
        plant->setRegionOfOrigin(regionOfOrigin);
    });
}

PlantModel *Actions::findByFamily(const DynamicVector<PlantModel> &plants, const std::string &family) {
    for(auto& element: plants){
        if(element.getFamily() == family){
            return &element;
        }
    }
    return nullptr;
}

void Actions::alterFamily(PlantModel *plant, const std::string &family) {
    _goAhead(plant,[&family](PlantModel* plant){
        plant->setRegionOfOrigin(family);
    });
}

PlantModel *Actions::findByScientificName(const DynamicVector<PlantModel> &plants, const std::string &scientificName) {
    for(auto& element : plants){
        if(element.getScientificName() == scientificName){
            return &element;
        }
    }

    return nullptr;
}

void Actions::alterScientificName(PlantModel *plant, const std::string &scientificName) {
    _goAhead(plant,[&scientificName](PlantModel* plant){
        plant->setRegionOfOrigin(scientificName);
    });
}
