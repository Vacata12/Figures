//
// Created by Ivan Stoynev on 11.11.24.
//

#include "../Headers/StreamFigureFactory.h"


StreamFigureFactory::StreamFigureFactory(std::unique_ptr<std::istream> input) : input(std::move(input)) {}

std::unique_ptr<Figure> StreamFigureFactory::create() {
    std::string line;
    std::getline(*input, line);
    std::ifstream file(line);
    if (file.is_open()) {
        std::getline(file, line);
        file.close();
        return StringFiguresFactory::createFromString(line);
    }
    else {
        return StringFiguresFactory::createFromString(line);
    }
    return nullptr;
}