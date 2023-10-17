//
// Created by arthur on 17/10/23.
//

#ifndef PRACTICALPROJECT_FILESYSTEMCLI_H
#define PRACTICALPROJECT_FILESYSTEMCLI_H

#include <filesystem>

#include "../../DynamicVector/DynamicVector.h"

namespace FileSystemCli{

    template<class T>
    DynamicVector<T>& load(std::filesystem::path& path);
}

#endif //PRACTICALPROJECT_FILESYSTEMCLI_H
