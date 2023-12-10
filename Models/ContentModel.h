//
// Created by arthur on 17/10/23.
//

#ifndef PRACTICALPROJECT_CONTENTMODEL_H
#define PRACTICALPROJECT_CONTENTMODEL_H

#include <filesystem>

#include "../DynamicVector/DynamicVector.h"

//Classe genérica responsável por obrigar com que as demais classes que herdem dela tenham, no mínimo, os seguintes métodos:
// - loadFromCsv
//      Método estático que recebe como argumento um arquivo aberto no modo de leitura a fim de que o objeto que o
//      encapsula, do tipo T, seja gerado.
// - saveInCsv
//      Método que recebe um arquivo aberto no modo de escrita, de modo que o conteúdo da instância da classe à qual ele
//      pertence seja salva no arquivo no formato CSV.
template<class T>
class ContentModel{
public:

    ContentModel() = default;

    static T loadFromCsv(std::ifstream&);

    virtual void saveInCsv(std::ofstream&) = 0;
};

#endif //PRACTICALPROJECT_CONTENTMODEL_H
