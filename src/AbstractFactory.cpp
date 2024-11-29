//
// Created by Ivan Stoynev on 13.11.24.
//
#include "../Headers/AbstractFactory.h"




std::unique_ptr<Factory> AbstractFactory::getFactory(std::unique_ptr<std::istream> stream) {
    if(!stream) {
        std::cout << "Invalid stream!\n";
    }
    std::string streamChoosen;
    *stream >> streamChoosen;
    if (streamChoosen == "random") {
        return std::unique_ptr<Factory>(new RandomGeneratorFigures());
    } 
    else if (streamChoosen == "stream") {
        stream->get();
        return std::unique_ptr<Factory>(new StreamFigureFactory(std::move(stream)));
    } 
    else {
        throw std::invalid_argument("Invalid input: " + streamChoosen);
    }
}