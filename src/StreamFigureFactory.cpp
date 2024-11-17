//
// Created by Ivan Stoynev on 11.11.24.
//

#include "../Headers/StreamFigureFactory.h"


StreamFigureFactory::StreamFigureFactory(std::istream* input) : input(input) {}

Figure * StreamFigureFactory::create() {
    std::string figure(std::istreambuf_iterator<char>(*input), {});
    return StringFiguresFactory::createFromString(figure);
}


