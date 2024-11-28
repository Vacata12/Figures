//
// Created by Ivan Stoynev on 11.11.24.
//

#include "../Headers/StreamFigureFactory.h"


StreamFigureFactory::StreamFigureFactory(std::istream* input) : input(input) {}

std::unique_ptr<Figure> StreamFigureFactory::create() {
    std::string line;
    if (std::getline(*input, line)) {  // Read one line from the stream
        return StringFiguresFactory::createFromString(line);
    }
    return nullptr; // Return nullptr if no input or end of stream
}