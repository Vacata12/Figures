//
// Created by Ivan Stoynev on 7.11.24.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Figure.h"
class Rectangle : public Figure {
private:
    double a = 0;
    double b = 0;
public:
    Rectangle() = default;
    Rectangle(const double& a, const double& b);
    double getPerimeter() const override;
    std::unique_ptr<Figure> clone() const override;
    std::string toString() const override;
};
#endif //RECTANGLE_H