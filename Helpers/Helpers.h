//
// Created by arthur on 09/11/23.
//

#ifndef PRACTICALPROJECT_HELPERS_H
#define PRACTICALPROJECT_HELPERS_H

#include <filesystem>
#include <functional>

namespace Helpers{

    ///Verifica se o caminho passado como argumento é um CSV, se for, executa a função anônima passada como argumento.
    [[maybe_unused]] void _goAheadIfFileIsCsv(const std::filesystem::path& path, const std::function<void(const std::filesystem::path& path)>& function);


    ///Verifica se o caminho passado como argumento é um válido, se for, executa a função anônima passada como argumento.
    [[maybe_unused]]void _goAheadIfPathIsValid(const std::filesystem::path& path, const std::function<void(const std::filesystem::path&)>& function);

    /// Função que permite verificar se um arquivo é binário e existe antes de prosseguir.
    void _goAheadIsPathIsBinaryFile(const std::filesystem::path &path, const std::function<void(const std::filesystem::path &)> &function);
}


#endif //PRACTICALPROJECT_HELPERS_H
