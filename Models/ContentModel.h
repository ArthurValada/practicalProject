//
// Created by arthur on 17/10/23.
//

#ifndef PRACTICALPROJECT_CONTENTMODEL_H
#define PRACTICALPROJECT_CONTENTMODEL_H

#include <filesystem>

#include "../DynamicVector/DynamicVector.h"

template<class T>
class ContentModel{
public:
    static T loadFromCsv(std::ifstream&);

    virtual void saveInCsv(std::ofstream&) = 0;
};

#endif //PRACTICALPROJECT_CONTENTMODEL_H
