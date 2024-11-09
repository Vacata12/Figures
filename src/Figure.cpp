//
// Created by Ivan Stoynev on 9.11.24.
//

#include "../Headers/Figure.h"


//helper functin to convert double to string with 2 decimal points
//example 3.1423 -> 3.14
std::string convertDoubleToString(double num) {
    std::ostringstream out;
    out << std::fixed << std::setprecision(2) << num;
    std::string result = out.str();

                             //std::string::npos == not found
    if (result.find(".00") != std::string::npos) {
        result = result.substr(0, result.size() - 3);
    }

    return result;
}