//
// Created by Ivan Stoynev on 9.11.24.
//
#include <iostream>
#include <memory>
#include "../Headers/Figure.h"
#include "../Headers/HelperFunctions.h"
#include "../Headers/AbstractFactory.h"


int main() {
    std::vector<std::unique_ptr<Figure> > Figures;
    AbstractFactory af;
    while (true) {
        std::cout << "Enter 'random' or 'stream' (or 'exit' to quit): ";
        std::string input;
        std::getline(std::cin, input);
        if (input == "exit") {
            break;
        }
        try {
            std::unique_ptr<std::istream> inputStream = std::unique_ptr<std::istream>(new std::istringstream(input));
            std::unique_ptr<Factory> factory = af.getFactory(std::move(inputStream));
            Figures.push_back(factory->create());
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }
    return 0;
}