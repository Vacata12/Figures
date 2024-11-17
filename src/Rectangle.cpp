//
// Created by Ivan Stoynev on 8.11.24.
//
#include "../Headers/Rectangle.h"

Rectangle::Rectangle(const double &a, const double &b) {
    if(checkForOverFlow({a, b})) {
        throw std::overflow_error("Overflow Error");
    }
    if(!positiveNums({a, b})) {
        throw std::invalid_argument("Sides of the Rectangle cannot be 0 or negative");
    }
    this->a = a;
    this->b = b;
    this->per = 2 * (a + b);
}

double Rectangle::getPerimeter() const {
    return per;
}

Figure * Rectangle::clone() const {
    return new Rectangle(*this);
}

std::string Rectangle::toString() const {
    return "Rectangle " + convertDoubleToString(a) + " " + convertDoubleToString(b);
}
