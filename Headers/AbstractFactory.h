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
    Factory* getFactory(const std::string& input, std::istream* stream = nullptr);
};

#endif //ABSTRACTFACTORY_H
