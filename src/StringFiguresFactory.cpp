//
// Created by Ivan Stoynev on 9.11.24.
//

#include "../Headers/StringFiguresFactory.h"


std::vector<double> StringFiguresFactory::getNums(const std::string &str) {
    std::vector<double> res;
    std::string helper = "";
    for(size_t i = 0; i < str.length(); i++) {
        if(str[i] == ' ') {
            res.push_back(std::stod(helper));
            helper = "";
        }
        else {
            helper += str[i];
        }
    }
    res.push_back(std::stod(helper));
    return res;
}

std::unique_ptr<Figure> StringFiguresFactory::createFromString(const std::string &representation) {
    if (representation.empty()) {
        return nullptr;
    }
    //find(' ') will return the position of the first whitespace
    size_t whiteSpace = representation.find(' ');
    if(whiteSpace == std::string::npos) {
        throw std::invalid_argument("Invalid representation!");
    }
    std::string figureType = representation.substr(0, whiteSpace);
    if(figureType == "Circle") {
        std::string radius = representation.substr(whiteSpace);
        return std::make_unique<Circle>(std::stod(radius));
    }
    else if(figureType == "Rectangle") {
        std::vector<double> sides = getNums(representation.substr(whiteSpace +1));
        return std::make_unique<Rectangle>(sides[0], sides[1]);
    }
    else if(figureType == "Triangle") {
        std::vector<double> sides = getNums(representation.substr(whiteSpace +1));
        return std::make_unique<Triangle>(sides[0], sides[1], sides[2]);
    }
    else {
        throw std::runtime_error("Invalid Figure");
    }
}