//
// Created by arthur on 17/10/23.
//

#include "fileSystem.h"

std::filesystem::path FileSystem::charToPath(const char *p) {

    std::filesystem::path path(p);

    return path;
}

template<std::size_t N>
std::filesystem::path FileSystem::charToPath(const char (&p)[N]) {
    std::filesystem::path path(p);

    return path;
}

bool FileSystem::isFile(const std::filesystem::path &path) {
    return std::filesystem::exists(path) && std::filesystem::is_regular_file(path);
}

bool FileSystem::isFile(const std::filesystem::path &&path) {
    return std::filesystem::exists(path) && std::filesystem::is_regular_file(path);
}

void FileSystem::createFile(const std::filesystem::path &path) {

    std::error_code errorCodeExists, errorCodeIsNotRegularFile;

    if(!(std::filesystem::exists(path, errorCodeExists) and std::filesystem::is_regular_file(path, errorCodeIsNotRegularFile))){
        std::ofstream file(path.c_str());
        file.close();
    }
    else{
        throw std::filesystem::filesystem_error("O arquivo já existe.", path,errorCodeIsNotRegularFile);
    }
}

void FileSystem::createFile(const std::filesystem::path &&path) {
    std::error_code errorCodeExists, errorCodeIsNotRegularFile;

    if(!(std::filesystem::exists(path, errorCodeExists) and std::filesystem::is_regular_file(path, errorCodeIsNotRegularFile))){
        std::ofstream file(path.c_str());
        file.close();
    }
    else {
        if (errorCodeExists) {
            throw std::filesystem::filesystem_error("O arquivo já existe.", path, errorCodeExists);
        }
        if(errorCodeIsNotRegularFile){
            throw std::filesystem::filesystem_error("O arquivo não é regular.",path, errorCodeIsNotRegularFile);
        }
    }
}

template<std::size_t N>
void FileSystem::createFile(const std::filesystem::path &path, const char (&name)[N]) {
    createFile(path/name);
}

template<std::size_t N>
void FileSystem::createFile(const std::filesystem::path &&path, const char (&name)[N]) {
    createFile(path/name);
}

template<std::size_t N>
void FileSystem::createFile(const std::filesystem::path &path, const char (&&name)[N]) {
    createFile(path/name);
}

template<std::size_t N>
void FileSystem::createFile(const std::filesystem::path &&path, const char (&&name)[N]) {
    createFile(path/name);
}

void FileSystem::createFile(const std::filesystem::path &path, const std::string &name) {
    createFile(path/name.c_str());
}



void FileSystem::createFile(const std::filesystem::path &&path, const std::string &name) {
    createFile(path/name);
}

std::basic_fstream<char>FileSystem::openFile(const std::filesystem::path &path) {
    return {path};
}

std::basic_fstream<char> FileSystem::openFile(const std::filesystem::path &&path) {
    return {path};
}



void FileSystem::deleteFile(const std::filesystem::path &path) {

    std::error_code errorCode;

    if(std::filesystem::remove(path, errorCode)){}
    else{
        throw std::filesystem::filesystem_error("Erro ao deletar o arquivo.",path, errorCode);
    }
}

void FileSystem::deleteFile(const std::filesystem::path &&path) {
    std::error_code errorCode;

    if(std::filesystem::remove(path, errorCode)){}
    else{
        throw std::filesystem::filesystem_error("Erro ao deletar o arquivo.",path, errorCode);
    }
}

bool FileSystem::isDirectory(const std::filesystem::path &path) {
    return std::filesystem::exists(path) and std::filesystem::is_directory(path);
}

bool FileSystem::isDirectory(const std::filesystem::path &&path) {
    return std::filesystem::exists(path) and std::filesystem::is_directory(path);
}

void FileSystem::createDirectory(const std::filesystem::path &path) {
    std::filesystem::create_directory(path);
}

void FileSystem::createDirectory(const std::filesystem::path &&path) {
    std::filesystem::create_directory(path);
}

void FileSystem::deleteDirectory(const std::filesystem::path &path) {
    std::filesystem::remove(path);
}

void FileSystem::deleteDirectory(const std::filesystem::path &&path) {
    std::filesystem::remove(path);
}

void FileSystem::deleteDirectoryContent(const std::filesystem::path &path) {
    if(path.has_filename() and is_empty(path.filename())){
        std::filesystem::remove_all(path);
    }
}

void FileSystem::deleteDirectoryContent(const std::filesystem::path &&path) {
    if(path.has_filename() and is_empty(path.filename())){
        std::filesystem::remove_all(path);
    }
}

DynamicVector<std::filesystem::path> FileSystem::list(const std::filesystem::path &path, bool absolutePath) {

    auto vector = DynamicVector<std::filesystem::path>();

    if(isDirectory(path)){
        if(absolutePath){
            std::ranges::for_each(std::filesystem::directory_iterator(path), std::filesystem::directory_iterator(),[&vector](auto element){
                vector.push_back(element);
            });
        }
        else{
            std::ranges::for_each(std::filesystem::directory_iterator(path), std::filesystem::directory_iterator(),[&vector](auto element){
                vector.push_back("./"/std::filesystem::path(element).filename());
            });
        }
    }

    return vector;
}

DynamicVector<std::filesystem::path> FileSystem::list(const std::filesystem::path &&path, bool absolutePath) {

    auto vector = DynamicVector<std::filesystem::path>();

    if(isDirectory(path)){
        if(absolutePath){
            std::ranges::for_each(std::filesystem::directory_iterator(path), std::filesystem::directory_iterator(),[&vector](auto element){
                vector.push_back(element);
            });
        }
        else{
            std::ranges::for_each(std::filesystem::directory_iterator(path), std::filesystem::directory_iterator(),[&vector](auto element){
                vector.push_back("./"/std::filesystem::path(element).filename());
            });
        }
    }

    return vector;
}

DynamicVector<std::filesystem::path> FileSystem::listDirectories(const std::filesystem::path &path, bool absolutePath) {

    auto vector = DynamicVector<std::filesystem::path>();

    if(is_directory(path)){
        if(absolutePath){
            std::ranges::for_each(std::filesystem::directory_iterator(path), std::filesystem::directory_iterator(), [&vector](auto element){
                auto directory = std::filesystem::path(element);
                if(is_directory(directory)){
                    vector.push_back(directory);
                }
            });
        }
        else{
            std::ranges::for_each(std::filesystem::directory_iterator(path), std::filesystem::directory_iterator(), [&vector](auto element){
                auto directory = std::filesystem::path(element);
                if(is_directory(directory)){
                    vector.push_back("./"/directory.filename());
                }
            });
        }
    }

    return vector;
}

DynamicVector<std::filesystem::path>
FileSystem::listDirectories(const std::filesystem::path &&path, bool absolutePath) {

    auto vector = DynamicVector<std::filesystem::path>();

    if(is_directory(path)){
        if(absolutePath){
            std::ranges::for_each(std::filesystem::directory_iterator(path), std::filesystem::directory_iterator(), [&vector](auto element){
                auto directory = std::filesystem::path(element);
                if(is_directory(directory)){
                    vector.push_back(directory);
                }
            });
        }
        else{
            std::ranges::for_each(std::filesystem::directory_iterator(path), std::filesystem::directory_iterator(), [&vector](auto element){
                auto directory = std::filesystem::path(element);
                if(is_directory(directory)){
                    vector.push_back("./"/directory.filename());
                }
            });
        }
    }

    return vector;
}

DynamicVector<std::filesystem::path> FileSystem::listFiles(const std::filesystem::path &path, bool absolutePath) {

    auto vector = DynamicVector<std::filesystem::path>();

    if(is_directory(path)){
        if(absolutePath){
            std::ranges::for_each(std::filesystem::directory_iterator(path), std::filesystem::directory_iterator(), [&vector](auto element){
                auto p = std::filesystem::path(element);
                if(is_regular_file(p)){
                    vector.push_back(p);
                }
            });
        }
        else{
            std::ranges::for_each(std::filesystem::directory_iterator(path), std::filesystem::directory_iterator(), [&vector](auto element){
                auto p = std::filesystem::path(element);
                if(is_regular_file(p)){
                    vector.push_back("./" / p.filename());
                }
            });
        }
    }

    return vector;
}

DynamicVector<std::filesystem::path> FileSystem::listFiles(const std::filesystem::path &&path, bool absolutePath) {

    auto vector = DynamicVector<std::filesystem::path>();

    if(is_directory(path)){
        if(absolutePath){
            std::ranges::for_each(std::filesystem::directory_iterator(path), std::filesystem::directory_iterator(), [&vector](auto element){
                auto p = std::filesystem::path(element);
                if(is_regular_file(p)){
                    vector.push_back(p);
                }
            });
        }
        else{
            std::ranges::for_each(std::filesystem::directory_iterator(path), std::filesystem::directory_iterator(), [&vector](auto element){
                auto p = std::filesystem::path(element);
                if(is_regular_file(p)){
                    vector.push_back("./" / p.filename());
                }
            });
        }
    }

    return vector;
}

template<std::size_t N>
void FileSystem::createDirectory(const std::filesystem::path &path, const char (&name)[N]) {
    createDirectory(path/name);
}

template<std::size_t N>
void FileSystem::createDirectory(const std::filesystem::path &path, const char (&&name)[N]) {
    createDirectory(path/name);
}

template<std::size_t N>
void FileSystem::createDirectory(const std::filesystem::path &&path, const char (&name)[N]) {
    createDirectory(path/name);
}

template<std::size_t N>
void FileSystem::createDirectory(const std::filesystem::path &&path, const char (&&name)[N]) {
    createDirectory(path/name);
}