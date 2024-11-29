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
        std::cout << "'random' -> creates random figure\n"
                  << "'stream Figure sides' -> example 'stream Rectangle 10 20'\n"
                  << "'stream filepath' -> use file input\n"
                  << "exit -> quit\n"
                  << "Enter command: ";
        std::string input;
        std::getline(std::cin, input);
        if (input == "exit") {
            break;
        }
        try {
            std::unique_ptr<std::istream> inputStream;
            if(input.substr(0, input.find(' ')) == "stream") {
                inputStream = std::unique_ptr<std::istream>(new std::istringstream(input));
            }
            else if(input == "random") {
                inputStream = std::unique_ptr<std::istream>(new std::istringstream(input));
            }
            std::unique_ptr<Factory> factory = af.getFactory(std::move(inputStream));
            Figures.push_back(factory->create());
            std::cout << "Figure added successfully\n";
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }
    return 0;
}