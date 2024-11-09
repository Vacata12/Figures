//
// Created by Ivan Stoynev on 7.11.24.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Figure.h"
class Triangle : public Figure {
private:
    double a;
    double b;
    double c;

    bool validateTriangle(const double& a, const double& b, const double& c);
public:
    Triangle() = default;
    Triangle(const double& a, const double& b, const double& c);
    double getPerimeter() const override;
    Figure* clone() const override;
    std::string toString() const override;
};


#endif //TRIANGLE_H
