//
// Created by arthur on 06/11/23.
//

#ifndef PRACTICALPROJECT_ACTIONS_H
#define PRACTICALPROJECT_ACTIONS_H

#include <functional>

#include "../DynamicVector/DynamicVector.h"
#include "../Models/PlantModel/PlantModel.h"

namespace Actions{

    ///Função responsável por verificar se o ponteiro passado como argumento não é nulo antes de executar a função anônima passada como argumento.
    void _goAhead(PlantModel* plant, const std::function<void(PlantModel*)>& pFunction);


    ///Função responsável por carregar os dados do CSV, recebendo como argumento um arguivo aberto.
    [[maybe_unused]] DynamicVector<PlantModel> loadFromCsv(std::ifstream& file);

    ///Função responsável por carregar os dados do CSV, recebendo como argumento o caminho do arquivo.
    [[maybe_unused]] DynamicVector<PlantModel> loadFromCsv(const std::filesystem::path&);


    ///Função responsável por salvar os dados em um arquivo csv CSV, recebendo como argumento um arguivo aberto.
    [[maybe_unused]] void saveInCsv(const DynamicVector<PlantModel>& plants, std::ofstream& file);

    ///Função responsável por salvar os dados em um arquivo csv CSV, recebendo como argumento o caminho do arguivo.
    [[maybe_unused]] void saveInCsv(const DynamicVector<PlantModel>& plants,const std::filesystem::path& filePath);


    ///Função responsável por carregar os dados do arquivo binário, recebendo como argumento um arguivo aberto.
    [[maybe_unused]] DynamicVector<PlantModel> loadFromBinary(std::ifstream& file);

    ///Função responsável por carregar os dados do arquivo binário, recebendo como argumento o caminho do arquivo..
    [[maybe_unused]] DynamicVector<PlantModel> loadFromBinary(const std::filesystem::path& path);


    ///Função responsável por salvar os dados em um arquivo binário, recebendo como argumento um arguivo aberto.
    [[maybe_unused]] void saveInBinary(const DynamicVector<PlantModel>& plants, std::ofstream& file);

    ///Função responsável por salvar os dados em um arquivo binário, recebendo como argumento o caminho do arquivo.
    [[maybe_unused]] void saveInBinary(const DynamicVector<PlantModel>& plants, const std::filesystem::path& path);


    ///Função responsável por achar a planta cujo id seja igual àquele passado como argumento.
    [[maybe_unused]] PlantModel* findById(const DynamicVector<PlantModel>& plants, int id);


    ///Função responsável por achar a planta cujo nome seja igual àquele passado como argumento.
    [[maybe_unused]] PlantModel* findByName(const DynamicVector<PlantModel>& plants, const std::string& name);
    ///Função responsável por alterar o nome da planta com base no ponteiro passado como argumento.
    [[maybe_unused]] void alterName(PlantModel* plant, const std::string& name);


    ///Função responsável por achar a planta cuja descrição seja igual àquela passada como argumento.
    [[maybe_unused]] PlantModel* findByDescription(const DynamicVector<PlantModel>& plants, const std::string& description);
    ///Função responsável por alterar a descrição da planta com base no ponteiro passado como argumento.
    [[maybe_unused]] void alterDescription(PlantModel* plant, const std::string& description);


    ///Função responsável por achar a planta cuja região de origem seja igual àquela passada como argumento.
    [[maybe_unused]] PlantModel* findByRegionOfOrigin(const DynamicVector<PlantModel>& plants, const std::string& regionOfOrigin);
    ///Função responsável por alterar a região de origem da planta com base no ponteiro passado como argumento.
    [[maybe_unused]] void alterRegionOfOrigin(PlantModel* plant, const std::string& regionOfOrigin);


    ///Função responsável por achar a planta cuja família de origem seja igual àquela passada como argumento.
    [[maybe_unused]] PlantModel* findByFamily(const DynamicVector<PlantModel>& plants, const std::string& family);
    ///Função responsável por alterar a família da planta com base no ponteiro passado como argumento.
    [[maybe_unused]] void alterFamily(PlantModel* plant, const std::string& family);


    ///Função responsável por achar a planta cujo nome científico seja igual àquele passado como argumento.
    [[maybe_unused]] PlantModel* findByScientificName(const DynamicVector<PlantModel>& plants, const std::string& scientificName);

    ///Função responsável por alterar o nome científico da planta com base no ponteiro passado como argumento.
    [[maybe_unused]] void alterScientificName(PlantModel* plant, const std::string& scientificName);

    [[maybe_unused]] void deletePlant(DynamicVector<PlantModel> content, PlantModel* plant, const std::filesystem::path& filePath);


    [[maybe_unused]] void sortByIdInAscendingOrder(DynamicVector<PlantModel> content);

    [[maybe_unused]] void sortByIdInDescendingOrder(DynamicVector<PlantModel> content);


    [[maybe_unused]] void sortByNameInAscendingOrder(DynamicVector<PlantModel> content);

    [[maybe_unused]] void sortByNameInDescendingOrder(DynamicVector<PlantModel> content);

    [[maybe_unused]] void showInRange(DynamicVector<PlantModel> content, std::size_t begin, std::size_t end);

    [[maybe_unused]] PlantModel* binarySearchBasedOnId(const PlantModel& element,DynamicVector < PlantModel > content, std::size_t begin, std::size_t end);
}

#endif //PRACTICALPROJECT_ACTIONS_H
