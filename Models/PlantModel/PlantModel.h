//
// Created by arthur on 26/10/23.
//

#ifndef PRACTICALPROJECT_PLANTMODEL_H
#define PRACTICALPROJECT_PLANTMODEL_H

///Inclusão das bibliotecas requeridas ao funcionamento da classe e de seus respectivos métodos.

#include <utility>
#include <fstream>
#include <iostream>

///Inclusão do arquivo de cabeçalho que descreve como a classe mãe, da qual PlantModel herda, se parece.

#include "../ContentModel.h"

///Declaração da classe PlantModel, feita a fim de representar o conceito de planta no escopo do projeto. Ela herda da
///classe mãe genérica ContentModel, tipada com o próprio PlantModel, a fim de que os métodos genéticos da classe mãe a
///serem sobrescritos tenham o tipo de retorno PlantModel, a classe filha.
class PlantModel : ContentModel<PlantModel> {

///Declaração dos atributos privados da classe, acessíveis por meio dos métodos de get e set, declarados mais à baixo na
///seção pública.

private:
    ///Atributo que representa o identificador.
    int _id{};

    bool _isActive;

    ///Atributo que representa o nome da planta.
    std::string _name;

    ///Atributo que representa a família a qual a planta pertence.
    std::string _family;

    ///Atributo que representa o nome scientífico da planta.
    std::string _scientificName;

    ///Atributo que representa a região de origem da planta.
    std::string _regionOfOrigin;

    ///Atributo responsável por representar a descrição da planta.
    std::string _description;

public:

    ///Construtor da classe responsável por inicializar os todos os atributos da classe.
    PlantModel(int id, std::string name, std::string family, std::string regionOfOrigin, std::string scientificName,
               std::string description, bool isActive = true);

    ///Construtor padrão da classe, não recebe argumentos.
    PlantModel() = default;


    ///Método estático da classe responsável por gerar um PlantModel a partir do conteúdo do arquivo passado como argumento.
    static PlantModel loadFromCsv(std::ifstream &file);
    ///Método responsável por fazer com que o conteúdo da instância da classe seja salvo no arquivo passado como argumento.
    void saveInCsv(std::ofstream &file) override ;


//    [[nodiscard]], segundo [Cpp Reference](https://en.cppreference.com/w/cpp/language/attributes/nodiscard),
//    é um atributo que indica, em tempo de compilação, que o retorno do método não deve ser descartado.

    ///Método de acesso ao id.
    [[nodiscard]] int getId() const;

    ///Método de acesso ao nome.
    [[nodiscard]] std::string getName() const;

    ///Método de acesso à família da planta.
    [[nodiscard]] std::string getFamily() const;

    ///Método de acesso à região de origem da planta.
    [[nodiscard]] std::string getRegionOfOrigin() const;

    ///Método de acesso ao nome scientífico da planta.
    [[nodiscard]] std::string getScientificName() const;

    ///Método de acesso à descrição da planta.
    [[nodiscard]] std::string getDescription() const;

    [[nodiscard]] bool getIsActive() const {
        return this->_isActive;
    }


    //Uma vez definido, o id não pode ser alterado.


    ///Método de alteração do nome da planta. Recebe como argumento um std::string que representa o novo nome da planta.
    ///Não possuí retorno, portanto, seu tipo é void.
    void setName(std::string newName);

    ///Método de alteração da família da planta. Recebe como argumento um std::string que representa a nova família à
    ///qual a planta pertence. Não possuí retorno, portanto, seu tipo é void.
    void setFamily(std::string family);

    ///Método de alteração da região de origem da planta. Recebe como argumrnto um std::string que representa a nova
    /// região de origem da planta. Não possuí retorno, portanto, seu tipo é void.
    void setRegionOfOrigin(std::string regionOfOrigin);

    ///Método de alteração do nome scientífico da planta. Recebe como argumrnto um std::string que representa o
    /// novo nome scientífico da planta. Não possuí retorno, portanto, seu tipo é void.
    void setScientificName(std::string scientificName);

    ///Método de alteração da descrição da planta. Recebe como argumrnto um std::string que representa a nova descrição
    /// da planta. Não possuí retorno, portanto, seu tipo é void.
    void setDescription(std::string description);

    [[maybe_unused]] void setIsActive(bool isActive);

    ///Sobrecarga do operador de comparação a fim de que duas instâncias da mesma classe sejam tidas como iguais tendo
    ///em vista a igualdade dos valores de sesu atributos.
    bool operator==(const PlantModel& other) const;

    ///Método responsável por mostrar a classe, seus atributos, na saída padrão.
    void show() const;

};

#endif //PRACTICALPROJECT_PLANTMODEL_H
