//
// Created by Ivan Stoynev on 9.11.24.
//

#ifndef RANDOMGENERATORFIGURES_H
#define RANDOMGENERATORFIGURES_H
#include <random>
#include "Factory.h"
#include "../Headers/Circle.h"
#include "../Headers/Rectangle.h"
#include "../Headers/Triangle.h"
class RandomGeneratorFigures : public Factory{
private:
    const double min = 0;
    const double max = 1000;
public:
    std::unique_ptr<Figure> create() override;
};


#endif //RANDOMGENERATORFIGURES_H