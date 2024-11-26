//
// Created by Ivan Stoynev on 9.11.24.
//

#ifndef STRINGFIGURESFACTORY_H
#define STRINGFIGURESFACTORY_H
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"


class StringFiguresFactory {
    static std::vector<double> getNums(const std::string& str);
public:
    StringFiguresFactory() = default;
    static std::unique_ptr<Figure> createFromString(const std::string& representation);
};



#endif //STRINGFIGURESFACTORY_H