//
// Created by Ivan Stoynev on 9.11.24.
//
#include <iostream>
#include "../Headers/Figure.h"
#include "../Headers/RandomGeneratorFigures.h"

void randGenFig(std::vector<std::unique_ptr<Figure> >& figures) {
    RandomGeneratorFigures randomFactory;
    while (true) {
        try {
            auto newFigure = randomFactory.create();
            figures.push_back(std::move(newFigure));
            std::cout << "Figure added successfully.\n";
            break;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << '\n';
        }
    }
}

int main() {
    std::vector<std::unique_ptr<Figure> > Figures;
    randGenFig(Figures);
    return 0;
}