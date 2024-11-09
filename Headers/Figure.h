//
// Created by Ivan Stoynev on 7.11.24.
//

#ifndef FIGURE_H
#define FIGURE_H
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>

class Figure {
protected:
    double per = 0;
public:
    virtual double getPerimeter() const = 0;
    virtual Figure* clone() const = 0;
    virtual std::string toString() const = 0;
    virtual ~Figure() = default;
};

std::string convertDoubleToString(double num);

#endif //FIGURE_H
