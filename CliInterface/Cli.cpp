//
// Created by arthur on 06/11/23.
//

#include "Cli.h"

[[maybe_unused]] void Cli::alterPlantName(const DynamicVector<PlantModel> &plants) {
    std::string newName;

    auto plant = find(plants);

    std::cout<<"Informe o novo nome da planta:";
    std::cin >> newName;
    try {
        Actions::_goAhead(plant, [&newName](PlantModel *plant) {
            Actions::alterName(plant, newName);
        });
    }
    catch (const std::invalid_argument& _){
        std::cerr<<"Não foi possível achar a planta com os dados fornecidos."<<std::endl;
    }
}

[[maybe_unused]] void Cli::alterPlantDescription(const DynamicVector<PlantModel> &plants) {
    std::string newDescription;

    auto plant = find(plants);

    std::cout<<"Informe a nova descrição da planta:";
    std::cin>>newDescription;

    try {
        Actions::_goAhead(plant, [&newDescription](PlantModel *plant) {
            Actions::alterDescription(plant, newDescription);
        });
    }
    catch (const std::invalid_argument& error){
        std::cerr<<"Não foi possível achar a planta com os dados fornecidos."<<std::endl;
    }
}

[[maybe_unused]] void Cli::alterPlantScientificName(const DynamicVector<PlantModel> &plants) {
    std::string newScientificName;

    auto plant = find(plants);

    std::cout<<"Informe o novo nome scientífico da planta:";
    std::cin>>newScientificName;

    try {
        Actions::_goAhead(plant, [&newScientificName](PlantModel *plant) {
            Actions::alterScientificName(plant, newScientificName);
        });
    }
    catch (const std::invalid_argument& error){
        std::cerr<<"Não foi possível achar a planta com os dados fornecidos."<<std::endl;
    }
}

[[maybe_unused]] void Cli::alterPlantFamily(const DynamicVector<PlantModel> &plants) {
    std::string newFamily;

    auto plant = find(plants);

    std::cout<<"Informe o novo nova família da planta:";
    std::cin>>newFamily;

    try {
        Actions::_goAhead(plant, [&newFamily](PlantModel *plant) {
            Actions::alterFamily(plant, newFamily);
        });
    }
    catch (const std::invalid_argument& error){
        std::cerr<<"Não foi possível achar a planta com os dados fornecidos."<<std::endl;
    }
}

[[maybe_unused]] void Cli::alterPlantRegionOfOrigin(const DynamicVector<PlantModel> &plants) {
    std::string newRegionOfOrigin;

    auto plant = find(plants);

    std::cout<<"Informe anova região de origem da planta:";
    std::cin>>newRegionOfOrigin;

    try {
        Actions::_goAhead(plant, [&newRegionOfOrigin](PlantModel *plant) {
            Actions::alterRegionOfOrigin(plant, newRegionOfOrigin);
        });
    }
    catch (const std::invalid_argument& error){
        std::cerr<<"Não foi possível achar a planta com os dados fornecidos."<<std::endl;
    }
}

[[maybe_unused]] void Cli::save(const DynamicVector<PlantModel> &plants) {

    std::filesystem::path filePath;

    std::cout<<"Informe o caminho com o nome do arquivo no qual deseja salvar as alterações:";
    std::cin>>filePath;

    if(filePath.has_extension()){
        try {
            Actions::saveInCsv(plants, filePath);
        }
        catch (const std::invalid_argument &_) {
            std::cerr << "Caminho inválido." << std::endl;
        }
    }
    else{
        Actions::saveInBinary(plants, filePath);
    }
}

[[maybe_unused]] PlantModel *Cli::findByRegionOfOrigin(const DynamicVector<PlantModel> &plants) {
    std::string regionOfOrigin;

    std::cout<<"Informe a região de origem da planta:";
    std::cin>>regionOfOrigin;

    return Actions::findByRegionOfOrigin(plants,regionOfOrigin);
}

[[maybe_unused]] PlantModel *Cli::findByFamily(const DynamicVector<PlantModel> &plants) {
    std::string family;

    std::cout<<"Informe a família da planta:";
    std::cin>>family;

    return Actions::findByFamily(plants, family);
}

[[maybe_unused]] PlantModel *Cli::findByScientificName(const DynamicVector<PlantModel> &plants) {
    std::string scientificName;

    std::cout<<"Informe o nome scientífico da planta:";
    std::cin>>scientificName;

    return Actions::findByScientificName(plants,scientificName);
}

[[maybe_unused]] PlantModel *Cli::findByDescription(const DynamicVector<PlantModel> &plants) {
    std::string description;

    std::cout<<"Informe a descrição da planta:";
    std::cin>>description;

    return Actions::findByDescription(plants, description);
}

[[maybe_unused]] PlantModel *Cli::findByName(const DynamicVector<PlantModel> &plants) {

    std::string name;

    std::cout<<"Informe o nome da planta:";
    std::cin>>name;

    return Actions::findByName(plants,name);
}

[[maybe_unused]] PlantModel *Cli::findById(const DynamicVector<PlantModel> &plants) {

    int id;

    std::cout<<"Informe o id da planta:";
    std::cin>>id;

    return Actions::findById(plants,id);
}

[[maybe_unused]] DynamicVector<PlantModel> Cli::load() {

    std::filesystem::path filePath;

    std::cout<<"Informe o caminho do arquivo do qual os dados serão carregados:";
    std::cin>>filePath;
    if(filePath.has_extension()){
        try {
            return Actions::loadFromCsv(filePath);
        }
        catch (const std::invalid_argument &_) {
            std::cerr << "O caminho é inválido." << std::endl;
        }
    }
    else{
        return Actions::loadFromBinary(filePath);
    }
    return {};
}

void Cli::menu() {
    DynamicVector<PlantModel> content = {};

    auto readOption = "Ler";
    auto findOption = "Buscar";
    auto alterOption = "Alterar";
    auto saveOption = "Salvar";
    auto exitOption = "Sair";

    std::map<int, const char *> options = {
            {1,readOption},
            {2,findOption},
            {3,alterOption},
            {4, saveOption},
            {5, exitOption},
    };

    auto outerShouldStop = false;

    while(not outerShouldStop){
        bool shouldStop = false;

        int choseOption;

        while (not shouldStop) {

            std::cout << "As opções que podem ser realizadas são:" << std::endl;

            for (const auto &option: options) {
                if (content.getSize() == 0 and strcmp(option.second, readOption) == 0) {
                    std::cout << "*";
                }
                std::cout << option.first << ". " << option.second << ";" << std::endl;
            }

            std::cout << "(*Recomendado)" << std::endl;
            std::cout << "Informe o número da opção de sua escolha:";
            std::cin >> choseOption;

            if (1 <= choseOption and choseOption <= options.size()) {
                shouldStop = true;
            } else {
                std::cerr << "Opção inválida, tente novamente." << std::endl;
            }
        }

        if (choseOption == 1) {
            content = load();
        } else if (choseOption == 2) {
            try {
                Actions::_goAhead(find(content), [](const PlantModel *plant) {
                    plant->show();
                });
            }
            catch(const std::invalid_argument& error){
                std::cerr<<"Não foi possível achar a planta com os dados fornecidos.";
            }
        } else if (choseOption == 3) {
            alter(content);
        } else if (choseOption == 4) {
            save(content);
        } else {
            outerShouldStop = true;
        }
    }
}

PlantModel *Cli::find(const DynamicVector<PlantModel> &plants) {

    std::map<int, const char*> options = {
            {1,"Buscar pelo Id"},
            {2, "Buscar pelo nome"},
            {3, "Buscar pelo nome scientífico"},
            {4, "Buscar pela família"},
            {5,"Buscar pela descrição"},
    };

    bool shouldStop = false;

    int choseOption;

    while(not shouldStop){

        std::cout<<"As opções que podem ser realizadas são:"<<std::endl;

        for (const auto &option: options) {
            std::cout<<option.first<<". "<<option.second<<";"<<std::endl;
        }

        std::cout<<"Informe o número da opção de sua escolha:";
        std::cin>>choseOption;

        if(1 <= choseOption and choseOption <= options.size()){
            shouldStop = true;
        }
        else{
            std::cerr<<"Opção inválida, tente novamente."<<std::endl;
        }
    }

    if(choseOption == 1){
        return findById(plants);
    }
    else if(choseOption == 2){
        return findByName(plants);
    }
    else if(choseOption == 3){
        return findByScientificName(plants);
    }
    else if(choseOption == 4){
        return findByFamily(plants);
    }
    else if(choseOption == 5){
        return findByDescription(plants);
    }

    return nullptr;
}

void Cli::alter(const DynamicVector<PlantModel> &plants) {
    std::cout<<"Escolha a opção pela qual alterar a Planta:"<<std::endl;

    std::map<int, const char*> options = {
            {1,"Alterar nome"},
            {2, "Alterar família"},
            {3, "Alterar nome scientífico"},
            {4, "Alterar descrição"}
    };

    bool shouldStop = false;

    int choseOption;

    while(not shouldStop){

        for (const auto &option: options) {
            std::cout<<option.first<<". "<<option.second<<";"<<std::endl;
        }

        std::cout<<"Informe o número da opção de sua escolha:";
        std::cin>>choseOption;

        if(1 <= choseOption and choseOption <= options.size()){
            shouldStop = true;
        }
        else{
            std::cerr<<"Opção inválida, tente novamente."<<std::endl;
        }
    }

    std::cout<<"Primeiro precisamos achar a Planta."<<std::endl;

    if(choseOption == 1){
        alterPlantName(plants);
    }
    else if(choseOption == 2){
        alterPlantFamily(plants);
    }
    else if(choseOption == 3){
        alterPlantScientificName(plants);
    }
    else if(choseOption == 4){
        alterPlantDescription(plants);
    }
}
