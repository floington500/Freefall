#include <bits/stdc++.h>
#include <iomanip>
#include <thread>
#include <cmath>
#include <string>
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
inline constexpr
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
inline constexpr 
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
inline constexpr
double timeForm(double d, double Vi, double Vf) 
{
	return d * 2 / (Vi + Vf);
}

void printColumn(int n)
{
	std::cout << "*\n"; // start column with rock at top
	for (int i = 0; i < n; ++i)
	{
		std::cout << "#\n";
	}
}

/**
 * Prepares the terminal enviornment for the simulation.
 */
void setup()
{
	system("clear");				   // clear the console
	std::cout.setf(std::ios::unitbuf); // turn off stdout buffer
	std::cout.sync_with_stdio(false);
	std::cout << "\033[?25l"; // disable cursor blinking
}

// usage:
// 	- '--help'
// 	- accleration rows
int main(int argc, char **argv)
{
	if (strcmp(argv[1], "--help") == 0)
	{
		std::cout << "Usage: freefall <distance> <time>" << std::endl;
		return 0;
	}
	setup();
	int dist = std::stoi(argv[1]);
	double time = std::stod(argv[2]);
	double acl = accelerationForm(dist, time);
		
	double v = velocityForm(0, acl, dist); // calculate initial velocity
	auto vv = new std::vector<double>{}; // vector for velocity vals

	// precompute velocity
	for (int i = 0; i < dist - 1; ++i) {
		v = velocityForm(v, acl, dist);
		vv->push_back(v);
	} 

	std::vector<double> vt;
	
	// precompute time 
	double prev = vv->at(0);
	double sum = 0;
	for (int i = 0; i < dist - 1; ++i) {
		std::cout << "Iteration: " << i << "\tInitial velocity: " << prev << "\tFinal Velocity: " << vv->at(i);
		double t = timeForm(i, prev, vv->at(i));
		sum += t;
		vt.push_back(t);
		prev = vv->at(i);
		std::cout << "\tResulting time: " <<  t << std::endl;
	}

	delete vv;
	std::cout << "Is sum and time equal?\tTime: " << time << "\tSum:" << sum << std::endl;

	getchar();	
	system("clear");				   // clear the console

	// print the column
	printColumn(dist);
	// move cursor to starting point
	std::cout << "\033[0;0H";
	sleep(1);

	for (auto t = vt.rbegin(); t != vt.rend(); ++t) {
		std::cout << "\033[1K"; // erase line
		std::cout << "\033[G";	// move cursor to beginning

		std::chrono::duration<double> dur (*t);	
		auto nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(dur);

		// add pound sign to beginning 
		std::cout << '#';

		std::cout << "\033[1B"; // move cursor down
		std::cout << "\033[1K"; // erase line
		std::cout << "\033[G";	// move cursor to beginning
		std::cout << '*';


		std::this_thread::sleep_for(std::chrono::nanoseconds(nanoseconds));
	}

	return 0;
}