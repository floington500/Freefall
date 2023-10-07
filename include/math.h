/**
 * @file math.h
 * @author Zach Appella
 * @brief Contains definitions for formulas involving
 * velocity and time.
 * @version 0.1
 * @date 2023-10-07
 * 
 * @copyright Copyright (c) 2023 Zach Appella
 * 
 * Licensed under the Creative Commons Attribution 1.0 Generic License.
 * You may obtain a copy of the License at:
 * https://creativecommons.org/licenses/by/1.0/
 */
#ifndef MATH_H
#define MATH_H

#include <vector>

double velocityForm(double, double, double);

double timeForm(double, double, double);

std::vector<double> computeVelocity(double, double);

std::vector<double> computeTime(double, std::vector<double>);

#endif // MATH_H