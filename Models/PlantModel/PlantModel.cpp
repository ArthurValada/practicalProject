//
// Created by arthur on 26/10/23.
//

///Importaçãpo do arquivo de cabeçalho com as definições dos métodos da classe PlantModel.
#include "PlantModel.h"


///Construtor da classe que recebe todos os argumentos a fim de instanciar a classe incializando todos os atributos.

//std::move é utilizado a vim de evitar com que uma string seja copiada em toda instanciação.
PlantModel::PlantModel(
        int id,
        std::string name,
        std::string family,
        std::string regionOfOrigin,
        std::string scientificName,
        std::string description
) :
        _id(id),
        _name(std::move(name)),
        _family(std::move(family)),
        _scientificName(std::move(scientificName)),
        _regionOfOrigin(std::move(regionOfOrigin)),
        _description(std::move(description)) {}


///Implementação do método loadFromCsv.
PlantModel PlantModel::loadFromCsv(std::ifstream &file) {

    ///As variáveis que contêm os dados a serem inseridos na instância são declarados.
    int id;
    std::string name;
    std::string scientificName;
    std::string family;
    std::string regionOfOrigin;
    std::string description;

    ///Uma variável do tipo char é criada para receber os caracteres que serão descartados.
    char trash;

    ///Se for possível ler o id da planta, a linha é tida como válida.
    if (file >> id) {

        ///A vírgula após o id é descartada.
        file >> trash;

        ///O conteúdo até a próxima vírgula é lido, ele representa o nome da planta.
        std::getline(file, name, ',');

        ///Como o std::getline move o leitor para o ponto seguinte à vírgula, não é necessário descartar a vírgula.

        ///A aspa simples é descartada.
        file>>trash;
        ///O conteúdo até a próxima aspa simples é obtido e armazenado na variável scientificName, o conteúdo representa
        ///o nome scientífico da planta.
        std::getline(file, scientificName, '\'');


        ///A vírgula subsequente é descartada.
        file>>trash;

        ///O conteúdo até a vírgula, excluso ela mesma, é pego e armazenado dentro da variável família.
        std::getline(file, family, ',');

        ///O abre aspas simples é descartado.
        file >> trash;
        ///O conteúdo entre as aspas é pego e armazenado na variável regionOfOrigin
        std::getline(file, regionOfOrigin, '\'');
        ///O fecha aspas simples é descartado.
        file>>trash;

        ///O abre aspas simples é descartado.
        file>>trash;
        ///O conteúdo entre as aspas é pego e armazenado na variável description
        std::getline(file, description, '\'');

        ///O resto é ignorado.
        file.ignore();

        ///O objeto é montado e retornado.
        return {id, name, family, regionOfOrigin, scientificName, description};
    }

    ///Caso não seja possível ler o id, um objeto vazio é retornado.
    return {};
}

///Função responsável por carregar os dados a partir de um arquivo CSV
void PlantModel::saveInCsv(std::ofstream &file) {

    ///Verifica se o arquivo é bom.
    if (file.good()) {

        ///Escreve o conteúdo.
        file << _id << ",\'" << _name << "\'," << _family << ",\'" << _regionOfOrigin << "\'," << _scientificName << "\',\'"
             << _description << "\'" << std::endl;
    }
}



/// Implementação da função para obter o Id do objeto.
int PlantModel::getId() const {

    ///Retorna o id da instância, acessada por meio do ponteiro this.
    return this->_id;
}

/// Implementação da função para obter o nome do objeto.
std::string PlantModel::getName() const {

    ///Retorna o nom da instância, acessada por meio do ponteiro this.
    return this->_name;
}

/// Implementação da função para obter a família do objeto.
std::string PlantModel::getFamily() const {

    ///Retorna oa família da instância, acessada por meio do ponteiro this.
    return this->_family;
}

/// Implementação da função para obter a região de origem do objeto.
std::string PlantModel::getRegionOfOrigin() const {

    ///Retorna a região de origem da instância, acessada por meio do ponteiro this.
    return this->_regionOfOrigin;
}

/// Implementação da função para obter o nome científico do objeto.
std::string PlantModel::getScientificName() const {

    ///Retorna o nome científico da instância, acessada por meio do ponteiro this.
    return this->_scientificName;
}

/// Implementação da função para obter a descrição do objeto.
std::string PlantModel::getDescription() const {

    ///Retorna a descrição da instância, acessada por meio do ponteiro this.
    return this->_description;
}


/// Implementação da função para alterar o nome do objeto.
void PlantModel::setName(std::string newName) {

    ///Altera o nome da instância.
    this->_name = std::move(newName);
}

/// Implementação da função para alterar a família do objeto.
void PlantModel::setFamily(std::string family) {

    ///Altera a família da instância.
    this->_family = std::move(family);
}

/// Implementação da função para alterar a região de origem do objeto.
void PlantModel::setRegionOfOrigin(std::string regionOfOrigin) {

    ///Altera a região de origem da instância.
    this->_regionOfOrigin = std::move(regionOfOrigin);
}

/// Implementação da função para alterar o nome científico do objeto.
void PlantModel::setScientificName(std::string scientificName) {

    ///Altera o nome científico da instância.
    this->_scientificName = std::move(scientificName);
}

/// Implementação da função para alterar a descrição do objeto.
void PlantModel::setDescription(std::string description) {

    ///Altera a descrição da instância.
    this->_description = std::move(description);
}


/// Implementação da sobrecarga do operador de igualdade a fim de comparar duas instância da mesma clasee.
bool PlantModel::operator==(const PlantModel& other) const {

    ///Compara o valor de cada um dos atributos da instância.
    return this->_id == other._id and this->_name == other._name and this->_description == other._description and
           this->_scientificName == other._scientificName and this->_regionOfOrigin == other._regionOfOrigin;
}

///Implementação da função show, responsável por exibir os dados do objeto no console.
void PlantModel::show() const {

    ///Exibe os atributos com as devidas legendas.
    std::cout<<"Id:"<<_id<<std::endl;
    std::cout<<"Nome:"<<_name<<std::endl;
    std::cout<<"Descrição:"<<_description<<std::endl;
    std::cout<<"Nome scientífico:"<<_scientificName<<std::endl;
    std::cout<<"Família:"<<_family<<std::endl;
    std::cout<<"Região de origem:"<<_regionOfOrigin<<std::endl;
}