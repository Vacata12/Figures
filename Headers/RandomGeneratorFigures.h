//
// Created by Ivan Stoynev on 9.11.24.
//

#ifndef RANDOMGENERATORFIGURES_H
#define RANDOMGENERATORFIGURES_H
#include <random>
#include "../Headers/Circle.h"
#include "../Headers/Rectangle.h"
#include "../Headers/Triangle.h"
class RandomGeneratorFigures {
private:
    static double min;
    static double max;
public:
    static Figure* createRandomFigure();
};


#endif //RANDOMGENERATORFIGURES_H
