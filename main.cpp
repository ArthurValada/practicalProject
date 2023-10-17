#include <iostream>

#include "./DynamicVector/DynamicVector.h"

int main(int argc, char* argv[]) {

    auto sla = DynamicVector({1,2,3,4});

    sla.push_back(3);

    for(auto element : sla){
        std::cout<<element<<std::endl;
    }

    return 0;
}
