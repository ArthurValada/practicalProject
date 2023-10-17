#include <iostream>

#include "./DynamicVector/DynamicVector.h"
#include "./fileSystem/fileSystem.h"

class Sla{
public:
    int a;
    Sla():a{}{}
    explicit Sla(int a): a(a){}
};

int main(int argc, char* argv[]) {

    auto sla = DynamicVector({
        Sla(1),
        Sla(2),
        Sla(3),
    });

    return 0;
}