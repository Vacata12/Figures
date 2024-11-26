//
// Created by Ivan Stoynev on 13.11.24.
//
#include "../Headers/AbstractFactory.h"



Factory * AbstractFactory::getFactory(const std::string &input, std::istream* stream) {
    if (input == "random") {
        return new RandomGeneratorFigures();
    }
    else if (input == "stream" && stream) {
        return new StreamFigureFactory(stream);
    }
    else {
        throw std::invalid_argument("Invalid stream or input");
    }
}