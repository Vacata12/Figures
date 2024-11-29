//
// Created by Ivan Stoynev on 11.11.24.
//

#include "../Headers/StreamFigureFactory.h"


StreamFigureFactory::StreamFigureFactory(std::unique_ptr<std::istream> input) : input(std::move(input)) {}

std::unique_ptr<Figure> StreamFigureFactory::create() {
    std::string line;
    if (std::getline(*input, line)) {
        return StringFiguresFactory::createFromString(line);
    }
    return nullptr;
}