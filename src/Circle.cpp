//
// Created by Ivan Stoynev on 7.11.24.
//
#include "../Headers/Circle.h"

Circle::Circle(const double &r) {
    if(!positiveNums({r})) {
        throw std::invalid_argument("Radius cannot be 0 or negative number");
    }
    this->r = r;
    this->per = 2 * 3.14 * r;
}

double Circle::getPerimeter() const {
    return per;
}

Figure * Circle::clone() const {
    return new Circle(*this);
}

std::string Circle::toString() const {
    //In docs says to use it before c++26 XD
    return  "Circle " + convertDoubleToString(r);
}
