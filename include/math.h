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

#include <cmath>
#include <vector>

namespace math
{
    /**
     * @brief computes the velocity of the rock
     *  *
     * @param Iv initial velocity
     * @param a  acceleration
     * @param s  the distance
     */
    constexpr inline double velocityForm(double Iv, double a, double s)
    {
        return std::sqrt(std::pow(Iv, 2) + 2 * a * s);
    }

    /**
     * @brief computes the time between two differences
     * in velocity
     *
     * @param d  distance
     * @param Vi initial velocity
     * @param Vf final velocity
     */
    constexpr inline double timeForm(double d, double Vi, double Vf)
    {
        return d * 2 / (Vi + Vf);
    }

    std::vector<double> computeVelocity(double);

    std::vector<double> computeTime(double, std::vector<double>);

} // namespace math

#endif // MATH_H