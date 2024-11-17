//
// Created by Ivan Stoynev on 13.11.24.
//

#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <initializer_list>
#include <limits>
#include <string>

std::string convertDoubleToString(double num);
/*
 * Those functions are designed to check the sides of various figures.
 * They use std::initializer_list<double> nums, allowing you to pass one or more arguments to the function.
 * For example, when checking the sides of rectangles and triangles,
 * you don't need to create separate functions for each figure type.
 * Instead, you can use this single function to handle all figures.
 * <limits> give me access to std::numeric_limits<double>::max()
 */
bool positiveNums(std::initializer_list<double> nums);
bool checkForOverFlow(std::initializer_list<double> nums);

#endif //HELPERFUNCTIONS_H
