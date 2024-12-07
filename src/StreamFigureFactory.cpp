//
// Created by Ivan Stoynev on 11.11.24.
//

#include "../Headers/StreamFigureFactory.h"


StreamFigureFactory::StreamFigureFactory(std::unique_ptr<std::istream> input) : input(std::move(input)) {
    std::string line;
    std::getline(*input, line);
    if(line.substr(0 , 16) == "stream filepath") {
        file = std::unique_ptr<std::ifstream>(new std::ifstream(line.substr(18)));
    }
}

std::unique_ptr<Figure> StreamFigureFactory::create() {
    if(this->file->is_open()) {
        std::string figure;
        std::getline(*file, figure);
        return StringFiguresFactory::createFromString(figure);
    }
    else {
        std::string figure;
        std::getline(*input, figure);
        return StringFiguresFactory::createFromString(figure);
    }
    return nullptr;
}