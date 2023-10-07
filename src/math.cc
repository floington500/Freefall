#include <cmath>
#include <vector>

/**
 * @brief computes the velocity of the rock
 *  *
 * @param Iv initial velocity
 * @param a  acceleration
 * @param s  the distance
 */
double velocityForm(double Iv, double a, double s)
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
double timeForm(double d, double Vi, double Vf)
{
	return d * 2 / (Vi + Vf);
}

/**
 * @brief assumes initial velocity of zero and solves for
 * the rest of the velocity values in the distance
 *  
 * @param a acceleration
 * @param d distance
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
		v = velocityForm(v, a, i);
	}

	return vv;
}

/**
 * @brief uses precomputed velocity values to calcuated the time
 * difference between each interval
 * 
 * @param d 
 * @param vv 
 * @return std::vector<double> 
 */
std::vector<double> computeTime(double d, std::vector<double> vv)
{
	std::vector<double> vt;

	for (int i = 1; i < vv.size(); ++i)
	{
		double t = timeForm(i, vv[i-1], vv.at(i));
		vt.push_back(t);
	} 

	return vt;
}