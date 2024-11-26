//
// Created by Ivan Stoynev on 8.11.24.
//
#include "../Headers/Triangle.h"

bool Triangle::validateTriangle(const double &a, const double &b, const double &c) {
    return a + b > c && a + c > b && b + c > a;
}

Triangle::Triangle(const double &a, const double &b, const double &c) {
    if(checkForOverFlow({a, b, c})) {
        throw std::overflow_error("Overflow Error");
    }
    if(!validateTriangle(a,b,c) || !positiveNums({a, b})) {
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

std::unique_ptr<Figure> Triangle::clone() const {
    return std::make_unique<Triangle>(*this);
}

std::string Triangle::toString() const {
    return "Triangle " + convertDoubleToString(a) + " " + convertDoubleToString(b) + " " + convertDoubleToString(c);
}