//
// Created by Ivan Stoynev on 9.11.24.
//
#include "../Headers/RandomGeneratorFigures.h"

Figure * RandomGeneratorFigures::create() {
    int figure = std::rand() % 3;
    std::uniform_real_distribution<double> unif(min,max);
    std::default_random_engine re;
    switch (figure) {
        case 0:
            return new Circle(unif(re));
        case 1:
            return new Rectangle (unif(re), unif(re));
        case 2:
            return new Triangle (unif(re), unif(re), unif(re));
    }
    return nullptr;
}
//saw that method here: https://www.geeksforgeeks.org/generate-random-double-numbers-in-cpp/
// std::uniform_real_distribution<double> unif(min,max);
// std::default_random_engine re;
// double random_double = unif(re);
// Time complexity: O(1).
// Auxiliary Space: O(1).