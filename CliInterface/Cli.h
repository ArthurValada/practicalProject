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

// COMENTARIOS APÓS A ADIÇÃO DO ARTHUR

    ///A função informa ao usuário que o conteúdo está sendo ordenado e, em seguida, 
    ///chama a função Actions::sortByIdInAscendingOrder() para ordenar o vetor DynamicVector<PlantModel> por ID em ordem crescente.
    [[maybe_unused]] void sortByIdInAscendingOrder(DynamicVector<PlantModel> content);

    /// Esta função é semelhante à função Cli::sortByIdInAscendingOrder(),
    /// com a diferença de que a função chama a função Actions::sortByIdInDescendingOrder() para realizar a ordenação em ordem decrescente.
    [[maybe_unused]] void sortByIdInDescendingOrder(DynamicVector<PlantModel> content);

    ///Esta função ordena o conteúdo de um vetor DynamicVector<PlantModel> por nome em ordem crescente. 
    ///A função imprime uma mensagem para o usuário informando que o conteúdo está sendo ordenado e, em seguida, chama a função Actions::sortByNameInAscendingOrder() para realizar a ordenação.
    [[maybe_unused]] void sortByNameInAscendingOrder(DynamicVector<PlantModel> content);

    ///Esta função é semelhante à função Cli::sortByNameInAscendingOrder(),
    /// com a diferença de que a função chama a função Actions::sortByNameInDescendingOrder() para realizar
    /// a ordenação por nome em ordem decrescente.
    [[maybe_unused]] void sortByNameInDescendingOrder(DynamicVector<PlantModel> content);

    ///Esta função permite que o usuário especifique um intervalo de índices e exibe as informações das plantas correspondentes no vetor content.
    [[maybe_unused]] void showInRange(DynamicVector<PlantModel>& content);

    ///Esta função permite ao usuário especificar o ID de uma planta e realiza uma busca binária no 
    ///vetor content para encontrar a planta correspondente. 
    [[maybe_unused]] PlantModel* binarySearchBasedOnId(DynamicVector<PlantModel>& content);

    ///Centraliza todas as opções que o usuário pode escolher.
    [[maybe_unused]] void menu();
}

#endif //PRACTICALPROJECT_CLI_H
