// Created by arthur on 09/11/23.

#include "Helpers.h"

///Essencialmente, essas funções agem como uma espécie de "guarda" para garantir que as condições necessárias sejam atendidas
/// antes de executar um determinado trecho de código.
/// Isso ajuda a evitar erros decorrentes de caminhos ou arquivos inválidos.


///Essa função verifica se o arquivo no caminho especificado existe e tem a extensão ".csv".
///Se essas condições forem atendidas, ela executa a função fornecida (function) passando o caminho como argumento. 
///Caso contrário, lança uma exceção.
void Helpers::_goAheadIfFileIsCsv(const std::filesystem::path &path, const std::function<void(const std::filesystem::path &)> &function) {
    if(exists(path) and path.extension() == ".csv"){
        function(path);
    }
    else{
        throw std::invalid_argument("The path passed as argument is invalid.");
    }

}

///Essa função verifica se o diretório pai do arquivo existe, se o arquivo existe e se tem a extensão ".csv". 
///Se todas essas condições forem atendidas, ela executa a função fornecida (function) passando o caminho como argumento. 
///Caso contrário, lança uma exceção.
void Helpers::_goAheadIfPathIsValid(const std::filesystem::path &path, const std::function<void(const std::filesystem::path &)> &function) {
    if(exists(path.parent_path()) and exists(path) and path.extension() == ".csv"){
        function(path);
    }
    else{
        throw std::invalid_argument("The path is invalid.");
    }
}

void Helpers::_goAheadIfPathIsBinaryFile(const std::filesystem::path &path, const std::function<void(const std::filesystem::path&)>& function) {
    if(exists(path.parent_path()) and exists(path) and not path.has_extension()){
        function(path);
    } else{
        throw std::invalid_argument("The path passed as argument isn't a binary file.");
    }
}
