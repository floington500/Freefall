#include <cmath>

/**
 * @brief Calculates the accleration that
 * will drive the rocks motion.
 *
 * Uses the formula:
 *
 * $d * 2 / t^2$
 *
 * @param d distance
 * @param t time
 */
double accelerationForm(double d, double t)
{
	return (d * 2) / std::pow(t, 2);
}

/**
 * @brief Computes the velocity of the rock using
 * the formula:
 * 
 * $v = \sqrt{Iv^2 + 2 * a * 2}$
 *
 * @param Iv initial velocity
 * @param a  acceleration
 * @param s  the distance
 */
double velocityForm(double Iv, double a, double s)
{
	return std::sqrt(std::pow(Iv, 2) + 2 * a * s);
}

/**
 * @brief Computes the time of a object falling
 * using the starting point as the frame of 
 * reference.
 * 
 * Uses the formula:
 * 
 * $t = \frac{2d}{V_i + V_f}$
 * 
 * @param d  distance
 * @param Vi initial velocity
 * @param Vf final velocity
 */
double timeForm(double d, double Vi, double Vf) 
{
	return d * 2 / (Vi + Vf);
}