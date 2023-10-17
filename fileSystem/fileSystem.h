//
// Created by arthur on 17/10/23.
//

#ifndef PRACTICALPROJECT_FILESYSTEM_H
#define PRACTICALPROJECT_FILESYSTEM_H

#include <filesystem>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>

#include "../DynamicVector/DynamicVector.h"

#pragma once

namespace FileSystem{

    std::filesystem::path charToPath(const char* p);
    template<std::size_t N>
    std::filesystem::path charToPath(const char (&p)[N]);
    std::filesystem::path stringToPath(std::string& name);

    bool isFile(const std::filesystem::path& path);
    bool isFile(const std::filesystem::path&& path);

    void createFile(const std::filesystem::path& path);
    void createFile(const std::filesystem::path&& path);

    template<std::size_t N>
    void createFile(const std::filesystem::path& path, const char (&name)[N]);
    template<std::size_t N>
    void createFile(const std::filesystem::path&& path, const char (&name)[N]);

    template<std::size_t N>
    void createFile(const std::filesystem::path& path, const char (&&name)[N]);
    template<std::size_t N>
    void createFile(const std::filesystem::path&& path, const char (&&name)[N]);

    void createFile(const std::filesystem::path& path, const std::string& name);
    void createFile(const std::filesystem::path&& path, const std::string& name);

    std::basic_fstream<char> openFile(const std::filesystem::path& path);
    std::basic_fstream<char> openFile(const std::filesystem::path&& path);

    void deleteFile(const std::filesystem::path& path);
    void deleteFile(const std::filesystem::path&& path);


    bool isDirectory(const std::filesystem::path& path);
    bool isDirectory(const std::filesystem::path&& path);

    void createDirectory(const std::filesystem::path& path);
    void createDirectory(const std::filesystem::path&& path);

    template<std::size_t N>
    void createDirectory(const std::filesystem::path& path, const char (&name)[N]);
    template<std::size_t N>
    void createDirectory(const std::filesystem::path& path, const char (&&name)[N]);

    template<std::size_t N>
    void createDirectory(const std::filesystem::path&& path, const char (&name)[N]);
    template<std::size_t N>
    void createDirectory(const std::filesystem::path&& path, const char (&&name)[N]);

    void deleteDirectory(const std::filesystem::path& path);
    void deleteDirectory(const std::filesystem::path&& path);

    void deleteDirectoryContent(const std::filesystem::path& path);
    void deleteDirectoryContent(const std::filesystem::path&& path);


    DynamicVector<std::filesystem::path> list(const std::filesystem::path& path, bool absolutePath = true);
    DynamicVector<std::filesystem::path> list(const std::filesystem::path&& path, bool absolutePath = true);

    DynamicVector<std::filesystem::path> listDirectories(const std::filesystem::path& path, bool absolutePath = true);
    DynamicVector<std::filesystem::path> listDirectories(const std::filesystem::path&& path, bool absolutePath = true);

    DynamicVector<std::filesystem::path> listFiles(const std::filesystem::path& path, bool absolutePath = true);
    DynamicVector<std::filesystem::path> listFiles(const std::filesystem::path&& path, bool absolutePath = true);

}

#endif //PRACTICALPROJECT_FILESYSTEM_H
