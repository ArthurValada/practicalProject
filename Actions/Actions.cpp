//

#include "Actions.h"
#include "../Helpers/Helpers.h"

// Created by arthur on 06/11/23.

void Actions::_goAhead(PlantModel *plant, const std::function<void(PlantModel *)> &pFunction) {
    if(plant != nullptr){
        pFunction(plant);
    }
    else{
        throw std::invalid_argument("The plant(: PlantModel*) should not be null.");
    }
}

DynamicVector<PlantModel> Actions::loadFromCsv(std::ifstream &file) {
    DynamicVector<PlantModel> plants = DynamicVector<PlantModel>();

    bool shouldStop = false;
    while(not shouldStop){
        PlantModel plant = PlantModel::loadFromCsv(file);
        if(plant != PlantModel()){
            plants.push_back(plant);
        }
        else{
            shouldStop = true;
        }
    }

    return plants;
}

void Actions::saveInCsv(const DynamicVector<PlantModel> &plants, std::ofstream &file) {
    if(file.good()){
        for(PlantModel& element : plants){
            element.saveInCsv(file);
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

DynamicVector<PlantModel> Actions::loadFromCsv(const std::filesystem::path& path) {

    DynamicVector content = DynamicVector<PlantModel>();

    Helpers::_goAheadIfPathIsValid(path, [&content](const std::filesystem::path &path) {
        std::ifstream file(path);

        bool shouldStop = false;

        while(not shouldStop){
            auto element = PlantModel::loadFromCsv(file);
            if(element!=PlantModel()){
                content.push_back(element);
            }
            else{
                shouldStop = true;
                if(content.getSize()==0){
                    throw std::invalid_argument("The file does not contains a PlantModel in CSV.");
                }
            }
        }

        file.close();
    });

    return content;
}

void Actions::saveInCsv(const DynamicVector<PlantModel> &plants, const std::filesystem::path& filePath) {
    if(exists(filePath.parent_path()) and not exists(filePath) and filePath.extension() == ".csv"){
        std::ofstream file(filePath);

        saveInCsv(plants, file);

        file.close();
    }
    else{
        throw std::invalid_argument("The path is invalid.");
    }
}

DynamicVector<PlantModel> Actions::loadFromBinary(std::ifstream &file) {

    file.seekg(0,std::ifstream::end);
    auto quantity = file.tellg();
    auto size = quantity / sizeof(PlantModel);

    auto* plants = new PlantModel[size];

    file.seekg(0, std::ifstream::beg);

    file.read((char*)plants, size * sizeof(PlantModel));

    return {plants, size};
}

DynamicVector<PlantModel> Actions::loadFromBinary(const std::filesystem::path &path) {

    std::ifstream file(path);
        auto plants = loadFromBinary(file);
    file.close();

    return plants;
}

void Actions::saveInBinary(const DynamicVector<PlantModel> &plants, std::ofstream &file) {
    file.write((const char*)plants.getData(), plants.getSize()* sizeof(PlantModel));
}

void Actions::saveInBinary(const DynamicVector<PlantModel> &plants, const std::filesystem::path &path) {
    std::ofstream file(path);
    saveInBinary(plants, file);
    file.close();
}