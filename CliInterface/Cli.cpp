// Created by arthur on 06/11/23.


#include "Cli.h"

///função que solicita ao usuário um novo nome para uma planta, tenta encontrar a planta no vetor e, se bem-sucedido,
/// utiliza a função alterName para alterar o nome da planta.
///Caso a planta não seja encontrada, uma mensagem de erro é exibida.
[[maybe_unused]] void Cli::alterPlantName(const DynamicVector<PlantModel> &plants) {
    std::string newName;

    auto plant = find(plants);

    std::cout<<"Informe o novo nome da planta:";
    std::cin >> newName;
    try {
        Actions::_goAhead(plant, [&newName](PlantModel *plant) {
            Actions::alterName(plant, newName);
        });
    }
    catch (const std::invalid_argument& _){
        std::cerr<<"Não foi possível achar a planta com os dados fornecidos."<<std::endl;
    }
}

///Esta função permite ao usuário alterar a descrição de uma planta em um DynamicVector<PlantModel>.
///A função funciona de maneira muito similar à função alterPlantName.
[[maybe_unused]] void Cli::alterPlantDescription(const DynamicVector<PlantModel> &plants) {
    std::string newDescription;

    auto plant = find(plants);

    std::cout<<"Informe a nova descrição da planta:";
    std::cin>>newDescription;

    try {
        Actions::_goAhead(plant, [&newDescription](PlantModel *plant) {
            Actions::alterDescription(plant, newDescription);
        });
    }
    catch (const std::invalid_argument& error){
        std::cerr<<"Não foi possível achar a planta com os dados fornecidos."<<std::endl;
    }
}

///A função solicita ao usuário um novo nome científico para uma planta, tenta encontrar a planta no vetor e, se bem-sucedido,
/// utiliza a função alterScientificName para alterar o nome científico da planta. 
///Caso a planta não seja encontrada, uma mensagem de erro é exibida.
[[maybe_unused]] void Cli::alterPlantScientificName(const DynamicVector<PlantModel> &plants) {
    std::string newScientificName;

    auto plant = find(plants);

    std::cout<<"Informe o novo nome scientífico da planta:";
    std::cin>>newScientificName;

    try {
        Actions::_goAhead(plant, [&newScientificName](PlantModel *plant) {
            Actions::alterScientificName(plant, newScientificName);
        });
    }
    catch (const std::invalid_argument& error){
        std::cerr<<"Não foi possível achar a planta com os dados fornecidos."<<std::endl;
    }
}

//////Função de intermédio ao usuário e à funcionalida para alterar a família da planta.
///A função funciona de maneira muito similar às outas funções "alter".
[[maybe_unused]] void Cli::alterPlantFamily(const DynamicVector<PlantModel> &plants) {
    std::string newFamily;

    auto plant = find(plants);

    std::cout<<"Informe o novo nova família da planta:";
    std::cin>>newFamily;

    try {
        Actions::_goAhead(plant, [&newFamily](PlantModel *plant) {
            Actions::alterFamily(plant, newFamily);
        });
    }
    catch (const std::invalid_argument& error){
        std::cerr<<"Não foi possível achar a planta com os dados fornecidos."<<std::endl;
    }
}

///A função que solicita ao usuário uma nova região de origem para uma planta, tenta encontrar a planta no vetor e, se bem-sucedido,
/// utiliza a função alterRegionOfOrigin para alterar a região de origem da planta. 
///Caso a planta não seja encontrada, uma mensagem de erro é exibida.
[[maybe_unused]] void Cli::alterPlantRegionOfOrigin(const DynamicVector<PlantModel> &plants) {
    std::string newRegionOfOrigin;

    auto plant = find(plants);

    std::cout<<"Informe anova região de origem da planta:";
    std::cin>>newRegionOfOrigin;

    try {
        Actions::_goAhead(plant, [&newRegionOfOrigin](PlantModel *plant) {
            Actions::alterRegionOfOrigin(plant, newRegionOfOrigin);
        });
    }
    catch (const std::invalid_argument& error){
        std::cerr<<"Não foi possível achar a planta com os dados fornecidos."<<std::endl;
    }
}

///Esta função permite ao usuário salvar as alterações feitas no conjunto de plantas em um arquivo. 
 ///Com base na presença ou ausência de uma extensão no caminho, decide se deve salvar os dados em formato CSV ou binário. 
 ///Em caso de caminho inválido, uma mensagem de erro é exibida.
[[maybe_unused]] void Cli::save(const DynamicVector<PlantModel> &plants) {

    std::filesystem::path filePath;

    std::cout<<"Informe o caminho com o nome do arquivo no qual deseja salvar as alterações:";
    std::cin>>filePath;

    if(filePath.has_extension()){
        try {
            Actions::saveInCsv(plants, filePath);
        }
        catch (const std::invalid_argument &_) {
            std::cerr << "Caminho inválido." << std::endl;
        }
    }
    else{
        Actions::saveInBinary(plants, filePath);
    }
}

///Esta função permite ao usuário pesquisar uma planta em um conjunto de plantas por sua região de origem. 
///A função solicita a região de origem ao usuário e chama a função Actions::findByRegionOfOrigin para realizar a pesquisa. 
///A função retorna um ponteiro à planta encontrada ou nullptr se nenhuma planta for encontrada.
[[maybe_unused]] PlantModel *Cli::findByRegionOfOrigin(const DynamicVector<PlantModel> &plants) {
    std::string regionOfOrigin;

    std::cout<<"Informe a região de origem da planta:";
    std::cin>>regionOfOrigin;

    return Actions::findByRegionOfOrigin(plants,regionOfOrigin);
}

///Esta função permite ao usuário pesquisar uma planta em um conjunto de plantas por sua família. 
///A função solicita a família ao usuário e chama a função Actions::findByFamily para realizar a pesquisa.
/// A função retorna um ponteiro à planta encontrada ou nullptr se nenhuma planta for encontrada.
[[maybe_unused]] PlantModel *Cli::findByFamily(const DynamicVector<PlantModel> &plants) {
    std::string family;

    std::cout<<"Informe a família da planta:";
    std::cin>>family;

    return Actions::findByFamily(plants, family);
}

///A função é semelhante às funções findByFamily e findByRegionOfOrigin, mas se diferencia por usar um critério de pesquisa mais preciso: o nome científico.
/// O nome científico é um identificador único e preciso para cada espécie, enquanto a família e a região de origem podem ser compartilhadas por várias espécies.
[[maybe_unused]] PlantModel *Cli::findByScientificName(const DynamicVector<PlantModel> &plants) {
    std::string scientificName;

    std::cout<<"Informe o nome scientífico da planta:";
    std::cin>>scientificName;

    return Actions::findByScientificName(plants,scientificName);
}

///Segue-se o principio de busca das funções "Cli::find". 
///A principal diferença entre esta função e as funções findByFamily, findByRegionOfOrigin, e findByScientificName é 
//o critério de pesquisa utilizado.
[[maybe_unused]] PlantModel *Cli::findByDescription(const DynamicVector<PlantModel> &plants) {
    std::string description;

    std::cout<<"Informe a descrição da planta:";
    std::cin>>description;

    return Actions::findByDescription(plants, description);
}


///A função Cli::findByName permite ao usuário pesquisar uma planta por seu nome comum.
[[maybe_unused]] PlantModel *Cli::findByName(const DynamicVector<PlantModel> &plants) {

    std::string name;

    std::cout<<"Informe o nome da planta:";
    std::cin>>name;

    return Actions::findByName(plants,name);
}

///Esta função permite ao usuário pesquisar uma planta em um conjunto de plantas por seu ID exclusivo.
///O ID é um identificador único para cada planta no conjunto de dados, 
///tornando a busca por ID a mais eficiente e precisa entre todas as funções de busca.
[[maybe_unused]] PlantModel *Cli::findById(const DynamicVector<PlantModel> &plants) {

    int id;

    std::cout<<"Informe o id da planta:";
    std::cin>>id;

    return Actions::findById(plants,id);
}

///Esta função permite ao usuário carregar dados de plantas de um arquivo. 
///A função solicita o caminho do arquivo, verifica a extensão do arquivo e, em seguida,
/// chama a função Actions::loadFromCsv(filePath) para arquivos CSV ou Actions::loadFromBinary(filePath) para arquivos binários. 
///A função retorna o objeto DynamicVector<PlantModel> contendo as plantas carregadas do arquivo.
[[maybe_unused]] DynamicVector<PlantModel> Cli::load() {

    std::filesystem::path filePath;

    std::cout<<"Informe o caminho do arquivo do qual os dados serão carregados:";
    std::cin>>filePath;
    if(filePath.has_extension()){
        try {
            return Actions::loadFromCsv(filePath);
        }
        catch (const std::invalid_argument &_) {
            std::cerr << "O caminho é inválido." << std::endl;
        }
    }
    else{
        return Actions::loadFromBinary(filePath);
    }
    return {};
}

///A função Cli::menu representa um menu interativo que permite realizar várias operações em um conjunto de dados de plantas.
///Ela implementa o menu principal da aplicação. 
///O menu permite ao usuário escolher entre as opções de ler, buscar, alterar e salvar plantas. 
///A função controla o fluxo da aplicação, chamando outras funções para realizar as ações correspondentes e exibindo mensagens para o usuário.
void Cli::menu() {
    DynamicVector<PlantModel> content = {};

    auto readOption = "Ler";
    auto findOption = "Buscar";
    auto alterOption = "Alterar";
    auto saveOption = "Salvar";
    auto exitOption = "Sair";

    auto deleteDirectOnFile = "Deletar diretamente no arquivo";
    auto sortText = "Ordenar";
    auto showInRangeText = "Mostrar intervalo";
    auto binarySearchBasedInId = "Busca binária baseada no id";
    auto sequentialSearchDirectOnFile = "Busca sequencial diretamente no arquivo";



    std::map<int, const char *> options = {
            {1,  readOption},
            {2,  findOption},
            {3,  alterOption},
            {4,  saveOption},
            {5,  exitOption},
            {6,  deleteDirectOnFile},
            {7,  sortText},
            {8,  showInRangeText},
            {9,  sequentialSearchDirectOnFile},
            {10, binarySearchBasedInId}
    };

    auto outerShouldStop = false;

    while(not outerShouldStop){
        bool shouldStop = false;

        int choseOption;

        while (not shouldStop) {

            std::cout << "As opções que podem ser realizadas são:" << std::endl;

            for (const auto &option: options) {
                if (content.getSize() == 0 and strcmp(option.second, readOption) == 0) {
                    std::cout << "*";
                }
                std::cout << option.first << ". " << option.second << ";" << std::endl;
            }

            std::cout << "(*Recomendado)" << std::endl;
            std::cout << "Informe o número da opção de sua escolha:";
            std::cin >> choseOption;

            if (1 <= choseOption and choseOption <= options.size()) {
                shouldStop = true;
            } else {
                std::cerr << "Opção inválida, tente novamente." << std::endl;
            }
        }

        if (choseOption == 1) {
            content = load();
        } else if (choseOption == 2) {
            try {
                Actions::_goAhead(find(content), [](const PlantModel *plant) {
                    plant->show();
                });
            }
            catch(const std::invalid_argument& error){
                std::cerr<<"Não foi possível achar a planta com os dados fornecidos.";
            }
        } else if (choseOption == 3) {
            alter(content);
        } else if (choseOption == 4) {
            save(content);
        } else if(choseOption == 5){
            outerShouldStop = true;
        } else if(choseOption == 6){
            deletePlantDirectlyInFile();
        } else if(choseOption == 7){
            sort(content);
        } else if(choseOption == 8){
            showInRange(content);
        } else if(choseOption == 9){
            directSequentialSearchInFile();
        } else{
            binarySearchBasedOnId(content);
        }
    }
}

///Esta função permite ao usuário escolher entre diferentes critérios para buscar uma planta.
///A função apresenta um menu de opções e, com base na escolha do usuário, chama a função de busca correspondente.
///A função retorna a planta encontrada ou nullptr se nenhuma planta for encontrada.
PlantModel *Cli::find(const DynamicVector<PlantModel> &plants) {

    std::map<int, const char*> options = {
            {1,"Buscar pelo Id"},
            {2, "Buscar pelo nome"},
            {3, "Buscar pelo nome scientífico"},
            {4, "Buscar pela família"},
            {5,"Buscar pela descrição"},
    };

    bool shouldStop = false;

    int choseOption;

    while(not shouldStop){

        std::cout<<"As opções que podem ser realizadas são:"<<std::endl;

        for (const auto &option: options) {
            std::cout<<option.first<<". "<<option.second<<";"<<std::endl;
        }

        std::cout<<"Informe o número da opção de sua escolha:";
        std::cin>>choseOption;

        if(1 <= choseOption and choseOption <= options.size()){
            shouldStop = true;
        }
        else{
            std::cerr<<"Opção inválida, tente novamente."<<std::endl;
        }
    }

    if(choseOption == 1){
        return findById(plants);
    }
    else if(choseOption == 2){
        return findByName(plants);
    }
    else if(choseOption == 3){
        return findByScientificName(plants);
    }
    else if(choseOption == 4){
        return findByFamily(plants);
    }
    else if(choseOption == 5){
        return findByDescription(plants);
    }

    return nullptr;
}

///Esta função permite ao usuário alterar os atributos de uma planta existente. A função exibe um menu de opções,
/// permite ao usuário escolher o atributo que deseja alterar e, em seguida, chama a função específica para realizar a alteração.
void Cli::alter(const DynamicVector<PlantModel> &plants) {
    std::cout<<"Escolha a opção pela qual alterar a Planta:"<<std::endl;

    std::map<int, const char*> options = {
            {1,"Alterar nome"},
            {2, "Alterar família"},
            {3, "Alterar nome scientífico"},
            {4, "Alterar descrição"}
    };

    bool shouldStop = false;

    int choseOption;

    while(not shouldStop){

        for (const auto &option: options) {
            std::cout<<option.first<<". "<<option.second<<";"<<std::endl;
        }

        std::cout<<"Informe o número da opção de sua escolha:";
        std::cin>>choseOption;

        if(1 <= choseOption and choseOption <= options.size()){
            shouldStop = true;
        }
        else{
            std::cerr<<"Opção inválida, tente novamente."<<std::endl;
        }
    }

    std::cout<<"Primeiro precisamos achar a Planta."<<std::endl;

    if(choseOption == 1){
        alterPlantName(plants);
    }
    else if(choseOption == 2){
        alterPlantFamily(plants);
    }
    else if(choseOption == 3){
        alterPlantScientificName(plants);
    }
    else if(choseOption == 4){
        alterPlantDescription(plants);
    }
}

[[maybe_unused]] void Cli::sortByIdInAscendingOrder(DynamicVector<PlantModel> content) {
    std::cout<<"O conteúdo do arquivo, que fora carregado na memória está a ser ordenado de forma crescente com base no Id."<<std::endl;
    Actions::sortByIdInAscendingOrder(content);
}

[[maybe_unused]] void Cli::sortByIdInDescendingOrder(DynamicVector<PlantModel> content) {
    std::cout<<"O conteúdo do arquivo, que fora carregado na memória está a ser ordenado de forma decrescente com base no Id."<<std::endl;
    Actions::sortByIdInDescendingOrder(content);
}

[[maybe_unused]] void Cli::sortByNameInAscendingOrder(DynamicVector<PlantModel> content) {
    std::cout<<"O conteúdo do arquivo, que fora carregado na memória está a ser ordenado de forma crescente com base no nome."<<std::endl;
    Actions::sortByNameInAscendingOrder(content);
}

[[maybe_unused]] void Cli::sortByNameInDescendingOrder(DynamicVector<PlantModel> content) {
    std::cout<<"O conteúdo do arquivo, que fora carregado na memória está a ser ordenado de forma decrescente com base no nome."<<std::endl;
    Actions::sortByNameInDescendingOrder(content);
}

[[maybe_unused]] void Cli::showInRange(DynamicVector<PlantModel>& content) {

    std::size_t begin;
    std::size_t end;

    std::cout<<"Informe o começo do intervalo:";
    std::cin>>begin;

    std::cout<<"Infore o fim do intervalo:";
    std::cin>>end;

    Actions::showInRange(content,begin, end);
}

[[maybe_unused]] PlantModel *Cli::binarySearchBasedOnId(DynamicVector<PlantModel> &content) {

    int id;

    std::cout<<"Informe o id da planta:";
    std::cin>>id;

    return Actions::binarySearchBasedOnId(id,content, 0, content.getSize());

}

void Cli::sort(DynamicVector<PlantModel> &content) {
    const char* sortByIdInAscendingOrder = "Ordenar por ID de forma crescente";
    const char* sortByIdInDescendingOrder = "Ordenar por ID de forma decrescente";
    const char* sortByNameInAscendingOrder = "Ordenar por nome de forma crescente";
    const char* sortByNameInDescendingOrder = "Ordenar por nome de forma decrescente";

    std::map<int, const char*> options ={
            {1,sortByIdInAscendingOrder},
            {2,sortByIdInDescendingOrder},
            {3,sortByNameInAscendingOrder},
            {4,sortByNameInDescendingOrder}
    };

    bool shouldStop = false;

    int selectedOption;
    while(not shouldStop){

        for(auto element : options){
            std::cout<<element.first<<"."<<element.second<<";"<<std::endl;
        }
        std::cout<<"Informe o número da opção de sua escolha:";
        std::cin>>selectedOption;

        if(1<=selectedOption and selectedOption<=4){
            shouldStop = true;
        }
        else{
            std::cerr<<"Opção inválida, tente novamente."<<std::endl;
        }
    }

    if(selectedOption == 1){
        Actions::sortByIdInAscendingOrder(content);
    }
    else if(selectedOption == 2){
        Actions::sortByIdInDescendingOrder(content);
    }
    else if(selectedOption == 3){
        Actions::sortByNameInAscendingOrder(content);
    }
    else{
        Actions::sortByNameInDescendingOrder(content);
    }
}

void Cli::deletePlantDirectlyInFile() {
    std::filesystem::path filePath;

    std::cout<<"Informe o caminho do arquivo binário:";
    std::cin>>filePath;
    try {
        Helpers::_goAheadIfPathIsBinaryFile(filePath, [](const std::filesystem::path &filePath) {

            int id;

            std::cout << "Informe o id da planta para que possamos deletá-la diretamente no arquivo:";
            std::cin >> id;

            Actions::deletePlant(id, filePath);
        });
    }
    catch(const std::invalid_argument& _){
        std::cerr<<"O caminho informado é inválido."<<std::endl;
    }
}

void Cli::directSequentialSearchInFile() {

    std::filesystem::path filePath;

    std::cout<<"Informe o caminho do arquivo binário:";
    std::cin>>filePath;

    try {
        Helpers::_goAheadIfPathIsBinaryFile(filePath, [](const auto &filePath) {

            int id;

            std::cout << "Informe o id da Planta:";
            std::cin >> id;

            PlantModel contentFind = Actions::directSequentialSearchInTheFile(id, filePath);

            if (contentFind == PlantModel()) {
                std::cerr << "Não foi possível achar a planta com o id informado." << std::endl;
            } else {
                std::cout << "A planta foi achada. Os dados são:" << std::endl;
                contentFind.show();
            }
        });
    }
    catch(const std::invalid_argument& _){
        std::cerr<<"O caminho passado como argumento é inválido."<<std::endl;
    }
}
