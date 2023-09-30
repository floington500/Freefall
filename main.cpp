#include <bits/stdc++.h>
#include <iomanip>
#include <thread>
#include <cmath>
#include <string>
#include <vector>

const double GRAVITY = 9.8;

/**
 * Calculates the acceleration which drives
 * the velocity for the rock.
 * 
 * @param d 
 * @param t 
 */
inline
double accelerationForm(double d, double t)
{
	return (d * 2) / std::pow(t, 2);
}

/**
 * Calculates the velocity of the rock.
 *
 * @param Iv initial velocity
 * @param a  acceleration
 * @param s  the distance
 */
inline 
double velocityForm(double Iv, double a, double s)
{
	return std::sqrt(std::pow(Iv, 2) + 2 * a * s);
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
		
	// print the column
	printColumn(dist);
	// move cursor to starting point
	std::cout << "\033[0;0H";

	sleep(1);

	// calculate initial velocity
	double v = velocityForm(0, acl, dist);
	std::vector<double> vv {v};

	// precompute velocity values 
	for (int i = 0; i < dist - 1; ++i) {
		v = velocityForm(v, acl, dist);
		vv.push_back(v);
	} 

	// iterate backwards to simulate acceleration
	for (auto it = vv.rbegin(); it != vv.rend(); it++) {
		std::cout << "\033[1K"; // erase line
		std::cout << "\033[G";	// move cursor to beginning

		// add pound sign to beginning 
		std::cout << '#';
		std::cout << "\t\t" << *it;

		std::cout << "\033[1B"; // move cursor down
		std::cout << "\033[1K"; // erase line
		std::cout << "\033[G";	// move cursor to beginning
		std::cout << '*';
		std::cout << "\t\t\t" << v << "\t\t\t" << GRAVITY-v;

		usleep(static_cast<int>(*it * 5000));
	}

	return 0;
}