//
// Created by arthur on 16/10/23.
//

#include "fileSystem.h"

bool FileSystem::fileExists(const std::filesystem::path &path) {
    return std::filesystem::exists(path) and !std::filesystem::is_directory(path);
}

bool FileSystem::directoryExists(const std::filesystem::path &path) {
    return std::filesystem::exists(path) and std::filesystem::is_directory(path);
}

void FileSystem::createDirectory(const std::filesystem::path &path) {
    std::filesystem::create_directory(path);
}

void FileSystem::deleteDirectory(const std::filesystem::path &path) {

    if(directoryExists(path)){
        std::filesystem::remove(path);
    }
    else{
        throw std::runtime_error("O diretório não existe");
    }

}

void FileSystem::deleteFile(const std::filesystem::path &path) {

    if(fileExists(path)){
        std::filesystem::remove(path);
    }
    else{
        throw std::runtime_error("O arquivo inexiste.");
    }

}

void FileSystem::deleteAllDirectoryContent(const std::filesystem::path &path) {

    if(directoryExists(path)){
        std::filesystem::path directoryPath= path / "/";
        std::filesystem::remove_all(directoryPath);
    }
    else{
        throw std::runtime_error("O diretório não existe.");
    }


}