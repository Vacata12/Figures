#pragma once
#include "Figure.h"
class Triangle : public Figure{
private:
    double a;
    double b;
    double c;

    bool validateTriangle(const double& a, const double& b, const double& c);
public:
    Triangle(const double& a, const double& b, const double& c);
    double getPerimeter() const override;
    std::unique_ptr<Figure> clone() const override;
    std::string toString() const override;
};