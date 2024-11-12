//
// Created by Ivan Stoynev on 11.11.24.
//

#ifndef STREAMFACTORY_H
#define STREAMFACTORY_H
#include "Factory.h"
#include "StringFiguresFactory.h"


class StreamFigureFactory : public Factory{
private:
    std::istream& input;
public:
    StreamFigureFactory(std::istream& input);
    Figure* create() override;
};

#endif //STREAMFACTORY_H
