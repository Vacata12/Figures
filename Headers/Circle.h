//
// Created by Ivan Stoynev on 7.11.24.
//

#ifndef CIRCLE_H
#define CIRCLE_H
#include "Figure.h"
class Circle : public Figure {
private:
    double r = 0;
public:
    Circle() =default;
    Circle(const double& r);
    double getPerimeter() const override;
    std::unique_ptr<Figure> clone() const override;
    std::string toString() const override;
};
#endif //CIRCLE_H