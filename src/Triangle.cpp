//
// Created by Ivan Stoynev on 8.11.24.
//
#include "../Headers/Triangle.h"

bool Triangle::validateTriangle(const double &a, const double &b, const double &c) {
    return a + b > c && a + c > b && b + c > a;
}

Triangle::Triangle(const double &a, const double &b, const double &c) {
    if(!validateTriangle(a,b,c)) {
        throw std::invalid_argument("Invalid triangle sides");
    }
    this->a = a;
    this->b = b;
    this->c = c;
    this->per = a + b + c;
}

double Triangle::getPerimeter() const {
    return per;
}

Figure * Triangle::clone() const {
    return new Triangle(*this);
}

std::string Triangle::toString() const {
    return "Triangle " + convertDoubleToString(a) + " " + convertDoubleToString(b) + " " + convertDoubleToString(c);
}
