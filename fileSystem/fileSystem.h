//
// Created by arthur on 16/10/23.
//

#ifndef PRACTICALPROJECT_FILESYSTEM_H
#define PRACTICALPROJECT_FILESYSTEM_H

#include <filesystem>
#include <algorithm>

namespace FileSystem{

    bool fileExists(const std::filesystem::path& path);

    void deleteFile(const std::filesystem::path& path);


    bool directoryExists(const std::filesystem::path& path);

    void createDirectory(const std::filesystem::path& path);

    void deleteDirectory(const std::filesystem::path& path);

    void deleteAllDirectoryContent(const std::filesystem::path& path);

}

#endif //PRACTICALPROJECT_FILESYSTEM_H
