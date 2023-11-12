//
// Created by arthur on 09/11/23.
//

#include "Helpers.h"

void Helpers::_goAheadIfFileIsCsv(const std::filesystem::path &path, const std::function<void(const std::filesystem::path &)> &function) {
    if(exists(path) and path.extension() == ".csv"){
        function(path);
    }
    else{
        throw std::invalid_argument("The path passed as argument is invalid.");
    }

}

void Helpers::_goAheadIfPathIsValid(const std::filesystem::path &path, const std::function<void(const std::filesystem::path &)> &function) {
    if(exists(path.parent_path()) and exists(path) and path.extension() == ".csv"){
        function(path);
    }
    else{
        throw std::invalid_argument("The path is invalid.");
    }
}
