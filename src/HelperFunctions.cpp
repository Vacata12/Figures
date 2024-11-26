
//
// Created by Ivan Stoynev on 13.11.24.
//

#include "../Headers/HelperFunctions.h"




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

bool positiveNums(std::initializer_list<double> nums) {
    for(double num : nums) {
        if(num <= 0) {
            return false;
        }
    }
    return true;
}

/* For example max is 10
 * We want to create a triangle with sides 5, 3, 4
 * 5 + 3 + 4 = 12 > 10
 * So we overflow
 */
bool checkForOverFlow(std::initializer_list<double> nums) {
    double max_double = std::numeric_limits<double>::max();
    double sum = 0.0;

    for (double num : nums) {
        if (num > max_double - sum) {
            return true;
        }
        sum += num;
    }

    return false;
}