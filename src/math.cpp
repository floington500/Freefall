#include <cmath>
#include <vector>

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

/**
 * @brief solves velocity for each whole number in
 * the range (0, d].
 *
 * @param a
 * @param d
 * @return std::vector<double>
 */
std::vector<double> computeVelocity(double a, double d)
{
	double v = velocityForm(0, a, d); // calculate initial velocity

	std::vector<double> vv; // vector for velocity vals

	// calculate velocity values
	for (int i = 0; i < d; ++i)
	{
  		vv.push_back(v);
		v = velocityForm(v, a, d);
	}

	return vv;
}

/**
 * @brief uses precomputed velocity values to calcuated the time
 * difference for the range of (0, d].
 * 
 * @param d 
 * @param vv 
 * @return std::vector<double> 
 */
std::vector<double> computeTime(double d, std::vector<double> vv)
{
	std::vector<double> vt;

	double prev = vv.at(0);
	for (int i = 1; i < vv.size(); ++i)
	{
		double t = timeForm(i, prev, vv.at(i));
		vt.push_back(t);
		prev = vv.at(i);
	} 

	return vt;
}