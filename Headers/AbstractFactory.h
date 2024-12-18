//
// Created by Ivan Stoynev on 13.11.24.
//

#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H
#include "StreamFigureFactory.h"
#include "RandomGeneratorFigures.h"

class AbstractFactory {
public:
    AbstractFactory() = default;
    std::unique_ptr<Factory> getFactory(std::unique_ptr<std::istream> stream);
};

#endif //ABSTRACTFACTORY_H