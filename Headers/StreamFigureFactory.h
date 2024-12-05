//
// Created by Ivan Stoynev on 11.11.24.
//

#ifndef STREAMFACTORY_H
#define STREAMFACTORY_H
#include "Factory.h"
#include "StringFiguresFactory.h"


class StreamFigureFactory : public Factory{
private:
    std::unique_ptr<std::istream> input = nullptr;
    std::unique_ptr<std::ifstream> file =  nullptr;
public:
    StreamFigureFactory(std::unique_ptr<std::istream> input);
    std::unique_ptr<Figure> create() override;
};

#endif //STREAMFACTORY_H