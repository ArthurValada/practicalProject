//
// Created by arthur on 09/11/23.
//

#ifndef PRACTICALPROJECT_HELPERS_H
#define PRACTICALPROJECT_HELPERS_H

#include <filesystem>
#include <functional>

namespace Helpers{
    [[maybe_unused]] void _goAheadIfFileIsCsv(const std::filesystem::path& path, const std::function<void(const std::filesystem::path& path)>& function);


    [[maybe_unused]]void _goAheadIfPathIsValid(const std::filesystem::path& path, const std::function<void(const std::filesystem::path&)>& function);
}


#endif //PRACTICALPROJECT_HELPERS_H
