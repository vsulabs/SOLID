#include "servicegood.h"

#include <iostream>

#include "Zone.h"
#include "GlobalZoneType.h"
#include "ConcreteZoneType.h"
#include "supply.h"

using namespace CppInject;
extern Zone globalZone;

Zone globalZone {&GlobalZoneType::instance};

IDataReader* makeReader(Zone& zone){
    return new StringReader("sum 1 2");
}

void dropReader(IDataReader* reader){
    return delete reader;
}

int main() {
    StringReader sr("sum 1 2");
    supply<IDataReader>::configure(makeReader, dropReader);
    ServiceGood sg;
    std::cout << sg.process();
    return 0;
}
