//
// Created by Ivan Stoynev on 9.11.24.
//
#include <iostream>
#include "../Headers/Figure.h"
#include "../Headers/HelperFunctions.h"
#include "../Headers/RandomGeneratorFigures.h"
#include "../Headers/StreamFigureFactory.h"

void randGenFig(std::vector<std::unique_ptr<Figure> >& figures);
void createFigThroughConsole(std::vector<std::unique_ptr<Figure> >& figures);
void createFigThroughFile(std::vector<std::unique_ptr<Figure> >& figures);

int main() {
    std::vector<std::unique_ptr<Figure> > Figures;
    createFigThroughFile(Figures);
    return 0;
}

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
void createFigThroughConsole(std::vector<std::unique_ptr<Figure> >& figures)
{
    std::cout << "Enter figure: ";
    StreamFigureFactory streamFactory(&std::cin);
    try {
            auto newFigure = streamFactory.create();
            figures.push_back(std::move(newFigure));
            std::cout << "Figure added successfully.\n";
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << '\n';
        }
    
}
void createFigThroughFile(std::vector<std::unique_ptr<Figure> >& figures)
{
    std::cout << "Enter file name: ";
    std::string fileName;
    std::cin >> fileName;
    std::ifstream file(fileName);
    if(!file.is_open()) {
        std::cout << "Invalid file name or path or file doesn't exist\n";
        file.close();
        return;
    }
    StreamFigureFactory streamFactory(&file);
    try {
        auto newFigure = streamFactory.create();
        figures.push_back(std::move(newFigure));
        std::cout << "Figure added successfully.\n";
        file.close();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        file.close();
    }
    file.close();
}