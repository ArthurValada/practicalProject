#include "Actions.h"
#include "../Helpers/Helpers.h"

// Created by arthur on 06/11/23.

///Essa função  realiza a ação (pFunction) no PlantModel, mas antes verifica se o ponteiro para esse objeto é nulo. 
//Se o ponteiro for nulo, uma exceção é lançada; caso contrário, a função de callback é executada. 
///Essa abordagem é útil para garantir que o objeto PlantModel seja válido antes de executar determinadas operações.
void Actions::_goAhead(PlantModel *plant, const std::function<void(PlantModel *)> &pFunction) {
    if(plant != nullptr){
        pFunction(plant);
    }
    else{
        throw std::invalid_argument("The plant(: PlantModel*) should not be null.");
    }
}

///A função lê plantas do CSV até encontrar o final do arquivo ou uma planta inválida.
///Aceita um arquivo aberto (std::ifstream) como entrada.
///As plantas válidas são adicionadas a um DynamicVector, que é então retornado.
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

///Esta função salva os dados das plantas contidas no vetor plants em um arquivo CSV, chamando o método saveInCsv de cada objeto PlantModel. 
///A verificação file.good() ajuda a garantir que a escrita no arquivo seja feita apenas se o arquivo estiver em um estado válido.
void Actions::saveInCsv(const DynamicVector<PlantModel> &plants, std::ofstream &file) {
    if(file.good()){
        for(PlantModel& element : plants){
            element.saveInCsv(file);
        }
    }
}

///Função responsável por achar uma planta — dentro do DynamicVector passado como argumento —, cujo identificador seja igual ao passado como argumento.
    PlantModel *Actions::findById(const DynamicVector<PlantModel> &plants, int id) {
        for(auto& element: plants){
            if(element.getId() == id){
                return &element;
            }
        }
        return nullptr;
    }

///A função busca uma planta pelo nome em um vetor dinâmico (DynamicVector<PlantModel>)
/// e retorna um ponteiro para a primeira instância encontrada com o nome correspondente. 
///Se nenhuma planta for encontrada com o nome especificado, a função retorna um ponteiro nulo (nullptr). 
PlantModel *Actions::findByName(const DynamicVector<PlantModel> &plants, const std::string &name) {
    for(auto& element : plants){
        if(element.getName() == name){
            return &element;
        }
    }
    return nullptr;
}

///Função responsável por alterar o nome da planta, cujo ponteiro foi passado como argumento, 
//de forma a coincidir com o novo nome passado como argumento para essa mesma função.
void Actions::alterName(PlantModel *plant, const std::string &name) {
    _goAhead(plant,[&name](PlantModel* plant){
        plant->setName(name);
    });
}

///Função responsável por achar uma planta cuja descrição seja igual à passada como argumento
PlantModel *Actions::findByDescription(const DynamicVector<PlantModel> &plants, const std::string &description) {
    for(auto& element : plants){
        if(element.getDescription() == description){
            return &element;
        }
    }

    return nullptr;
}

///Função responsável por fazer a alteração da descrição da planta conforme o novo valor, por meio de um ponteiro.
void Actions::alterDescription(PlantModel *plant, const std::string &description) {
    _goAhead(plant,[&description](PlantModel* plant){
        plant->setName(description);
    });
}

///Função responsável por fazer a busca dentro do DynamicVector a fim de encontrar uma planta cuja região de origem seja igual à passada como argumento.
PlantModel *Actions::findByRegionOfOrigin(const DynamicVector<PlantModel> &plants, const std::string &regionOfOrigin) {
    for(auto& element: plants){
        if(element.getRegionOfOrigin() == regionOfOrigin){
            return &element;
        }
    }

    return nullptr;
}

/// A função alterRegionOfOrigin utiliza a função _goAhead para encapsular a operação de alteração da região de origem da planta,
/// garantindo que a planta seja válida (não nula) antes de realizar a modificação.
void Actions::alterRegionOfOrigin(PlantModel *plant, const std::string &regionOfOrigin) {
    _goAhead(plant,[&regionOfOrigin](PlantModel* plant){
        plant->setRegionOfOrigin(regionOfOrigin);
    });
}

/// função percorre o vetor de plantas, compara a família de cada planta com a família fornecida e
/// retorna um ponteiro para a primeira planta encontrada com a família correspondente ou nullptr se nenhuma planta for encontrada.
PlantModel *Actions::findByFamily(const DynamicVector<PlantModel> &plants, const std::string &family) {
    for(auto& element: plants){
        if(element.getFamily() == family){
            return &element;
        }
    }
    return nullptr;
}

///A função alterFamily utiliza a função _goAhead para encapsular a operação de alteração da família da planta, 
///garantindo que a planta seja válida (não nula) antes de realizar a modificação. 
void Actions::alterFamily(PlantModel *plant, const std::string &family) {
    _goAhead(plant,[&family](PlantModel* plant){
        plant->setRegionOfOrigin(family);
    });
}

///Função responsável por achar, dentro do DynamicVector passado como argumento,
///uma planta cujo nome científico seja igual aopassado como argumento.
PlantModel *Actions::findByScientificName(const DynamicVector<PlantModel> &plants, const std::string &scientificName) {
    for(auto& element : plants){
        if(element.getScientificName() == scientificName){
            return &element;
        }
    }

    return nullptr;
}

///Função responsável por alterar o nome científico da planta – por meio do ponteiro passado como argumento — de modo a
/// coincidir com o novo nome científico passado como argumento.
void Actions::alterScientificName(PlantModel *plant, const std::string &scientificName) {
    _goAhead(plant,[&scientificName](PlantModel* plant){
        plant->setRegionOfOrigin(scientificName);
    });
}


/// Repare o mesmo nome "loadFromCsv" usado anteriormente, porém as funções se diferem nos argumentos recebidos e como interagem entre si, 
/// a 1° utilizando um arquivo aberto e a 2° recebendo o caminho do arquivo.
///A função a seguir lê plantas de um arquivo CSV especificado pelo caminho fornecido e as armazena em um vetor dinâmico. 
///A função inclui verificações de validade do caminho, do conteúdo lido e do tamanho do vetor resultante.
/// Se o arquivo não contiver uma planta válida, uma exceção é lançada.
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