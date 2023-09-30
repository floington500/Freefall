#include <bits/stdc++.h>
#include <iomanip>
#include <thread>
#include <cmath>
#include <stdlib.h>
#include <string>

/**
 * Calculates the acceleration which will set the
 * rock in motion.
 *
 * @param d distance
 * @param t time
 */
inline double accelerationForm(double d, double t)
{
	return d/t;
	//return (d * 2) / std::pow(t, 2);
}

/**
 * Calculates the velocity of the rock.
 *
 * @param Iv initial velocity
 * @param a  acceleration
 * @param s  the distance
 */
inline double velocityForm(double Iv, double a, double s)
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
void setup(int dist)
{
	system("clear");				   // clear the console
	std::cout.setf(std::ios::unitbuf); // turn off stdout buffer
	std::cout.sync_with_stdio(false);
	std::cout << "\033[?25l"; // disable cursor blinking
	// print the column
	printColumn(dist);
	// move cursor to starting point
	std::cout << "\033[0;0H";
}

// usage:
// 	- '--help'
// 	- vertical_accleration rows
int main(int argc, char **argv)
{
	if (argv[1] == "--help")
	{
		std::cout << "Usage: freefall <distance> <time>" << std::endl;
		return 0;
	}
	int distance = std::stoi(argv[1]);
	double time = std::stoi(argv[2]);
	double originalTime = time;
	double acl = 9.8;
	setup(distance);
	sleep(1);

	// calculate initial velocity
	double v = velocityForm(0, acl, distance);

	// increases loop at interval of one
	for (int pos = 0; pos < distance; ++pos) {
		std::cout << "\033[1K"; // erase line
		std::cout << "\033[G";	// move cursor to beginning

		// replace line with pound sign
		std::cout << '#';
		std::cout << "\t\t\t" << v;

		std::cout << "\033[1B";
		std::cout << "\033[1K"; // erase line
		std::cout << "\033[G";	// move cursor to beginning
		std::cout << '*';

		usleep(v * 10000);
		v = velocityForm(v+pos, acl, distance);
	}

	return 0;
}