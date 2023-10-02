#include <bits/stdc++.h>
#include <iomanip>
#include <string>

#include "math.h"

constexpr double GRAVITY = 9.8;

void printColumn(int n)
{
	for (int i = 0; i < n; ++i)
	{
		std::cout << "# \n";
	}
}

/**
 * Prepares the terminal emulator for the simulation.
 */
void setup()
{
	system("clear"); // clear the console
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
		std::cout << "Usage: freefall <distance>" << std::endl;
		return 0;
	}
	setup();

	int d = std::stoi(argv[1]);
	auto vt = computeTime(d, 
		computeVelocity(GRAVITY, d)
	);

	// print the column for the rock to drop from
	printColumn(d);
	std::cout << "\033[0;2H"; // move cursor to [0][2]

	for (auto t = vt.rbegin(); t != vt.rend(); ++t) {
		std::cout << "*";
	
		usleep(*t * 1000000);

		std::cout << "\b";
		std::cout << "\033[B";
	}

	return 0;
}