//
// Created by arthur on 06/11/23.
//

#ifndef PRACTICALPROJECT_CLI_H
#define PRACTICALPROJECT_CLI_H


///Inclusão dos cabeçaljos requeridos
#include <initializer_list>
#include <utility>
#include <string>
#include <functional>
#include <iostream>
#include <cstring>
#include <map>

///Inclusão do cabeçalho de Actions - será usado em Cli.cpp
#include "../Actions/Actions.h"
#include "../Helpers/Helpers.h"

namespace Cli{

    ///Função de interface para informar o caminho do qual carregar os dados.
    [[maybe_unused]] DynamicVector<PlantModel> load();

    ///Função de intermédio para perguntar ao usuário o caminho no qual salvar o conteúdo.
    [[maybe_unused]] void save(const DynamicVector<PlantModel>& plants);

    ///Função para perguntar o id e fazer uma busca linear para achar o elemento cujo id corresponda
    ///ao informado pelo usuário.
    [[maybe_unused]] PlantModel* findById(const DynamicVector<PlantModel> &plants);

    ///Função para perguntar o nome e fazer uma busca linear para achar o elemento cujo nome corresponda
    ///ao informado pelo usuário.
    [[maybe_unused]] PlantModel* findByName(const DynamicVector<PlantModel>& plants);

    ///Função para perguntar a descrição e fazer uma busca linear para achar o elemento cuja descrição corresponda
    ///ao informado pelo usuário.
    [[maybe_unused]] PlantModel* findByDescription(const DynamicVector<PlantModel>& plants);

    ///Função para perguntar o nome científico e fazer uma busca linear para achar o elemento cujo nome científico corresponda
    ///ao informado pelo usuário.
    [[maybe_unused]] PlantModel* findByScientificName(const DynamicVector<PlantModel>& plants);

    ///Função para perguntar a família e fazer uma busca linear para achar o elemento cuja família corresponda
    ///ao informado pelo usuário.
    [[maybe_unused]] PlantModel* findByFamily(const DynamicVector<PlantModel>& plants);

    ///Função para perguntar a região de origem e fazer uma busca linear para achar o elemento cuja região de origem corresponda
    ///ao informado pelo usuário.
    [[maybe_unused]] PlantModel* findByRegionOfOrigin(const DynamicVector<PlantModel>& plants);


    ///Função de escolha para que o usuário defina com qual submódulo vai interagir.
    PlantModel* find(const DynamicVector<PlantModel>& plants);


    ///Função de intermédio ao usuário e à funcionalida para alterar o nome da planta.
    [[maybe_unused]] void alterPlantName(const DynamicVector<PlantModel>& plants);

    ///Função de intermédio ao usuário e à funcionalida para alterar a descrição da planta.
    [[maybe_unused]] void alterPlantDescription(const DynamicVector<PlantModel>& plants);

    ///Função de intermédio ao usuário e à funcionalida para alterar o nome científico da planta.
    [[maybe_unused]] void alterPlantScientificName(const DynamicVector<PlantModel>& plants);

    ///Função de intermédio ao usuário e à funcionalida para alterar a família da planta.
    [[maybe_unused]] void alterPlantFamily(const DynamicVector<PlantModel>& plants);

    ///Função de intermédio ao usuário e à funcionalida para alterar a região de origem da planta.
    [[maybe_unused]] void alterPlantRegionOfOrigin(const DynamicVector<PlantModel>& plants);


    ///Função para que o usuário escolha com qual subinterface ele vai interagir.
    [[maybe_unused]] void alter(const DynamicVector<PlantModel>& plants);


    [[maybe_unused]] void sortByIdInAscendingOrder(DynamicVector<PlantModel> content);

    [[maybe_unused]] void sortByIdInDescendingOrder(DynamicVector<PlantModel> content);


    [[maybe_unused]] void sortByNameInAscendingOrder(DynamicVector<PlantModel> content);

    [[maybe_unused]] void sortByNameInDescendingOrder(DynamicVector<PlantModel> content);


    [[maybe_unused]] void sort(DynamicVector<PlantModel>& content);


    [[maybe_unused]] void showInRange(DynamicVector<PlantModel>& content);


    [[maybe_unused]] PlantModel* binarySearchBasedOnId(DynamicVector<PlantModel>& content);

    [[maybe_unused]] void deletePlantDirectlyInFile();

    ///Centraliza todas as opções que o usuário pode escolher.
    [[maybe_unused]] void menu();
}

#endif //PRACTICALPROJECT_CLI_H
