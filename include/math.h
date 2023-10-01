#ifndef MATH_H
#define MATH_H

#include <vector>

double accelerationForm(double, double);

double velocityForm(double, double, double);

double timeForm(double, double, double);

std::vector<double> *computeVelocity(double, double);

std::vector<double> computeTime(double, std::vector<double>*);

#endif // MATH_H