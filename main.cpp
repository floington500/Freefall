#include <bits/stdc++.h>
#include <iomanip>
#include <thread>
#include <cmath>
#include <string>

const double GRAVITY = 9.8;

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
	if (argv[1] == "--help")
	{
		std::cout << "Usage: freefall <distance> <time>" << std::endl;
		return 0;
	}
	setup();
	int dist = std::stoi(argv[1]);
	double time = std::stoi(argv[2]);
		
	// print the column
	printColumn(dist);
	// move cursor to starting point
	std::cout << "\033[0;0H";

	sleep(1);

	// calculate initial velocity
	double v = velocityForm(0, GRAVITY, dist);

	// increases loop at interval of one
	for (int pos = 0; pos < dist; ++pos) {
		std::cout << "\033[1K"; // erase line
		std::cout << "\033[G";	// move cursor to beginning

		// replace line with pound sign
		std::cout << '#';

		std::cout << "\033[1B";
		std::cout << "\033[1K"; // erase line
		std::cout << "\033[G";	// move cursor to beginning
		std::cout << '*';

		usleep(v * 10000);
		v = velocityForm(v+pos, GRAVITY, dist);
	}

	return 0;
}