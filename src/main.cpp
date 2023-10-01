#include <bits/stdc++.h>
#include <iomanip>
#include <thread>
#include <string>
#include <vector>

#include "math.h"

constexpr double GRAVITY = 9.8;

void printColumn(int n)
{
	std::cout << "*\n"; // start column with rock at top
	for (int i = 0; i < n; ++i)
	{
		std::cout << "#\n";
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
		std::cout << "Usage: freefall <distance> <time>" << std::endl;
		return 0;
	}
	setup();

	int d = std::stoi(argv[1]);
	auto vt = computeTime(d, 
		computeVelocity(GRAVITY, d)
	);
	
	// for (int i = 0; i < vt.size(); i++) {
	// 	std::cout << "Value at index " << i << ":" << vt.at(i) << "\n";
	// }

	// print the column for the rock to drop from
	printColumn(d);
	// move cursor to starting point
	std::cout << "\033[0;0H";
	sleep(1);

	for (auto t = vt.rbegin(); t != vt.rend(); ++t) {
		std::cout << "\033[1K"; // erase line
		std::cout << "\033[G";	// move cursor to beginning
	
		// add pound sign to beginning 
		std::cout << '#';

		std::cout << "\033[1B"; // move cursor down
		std::cout << "\033[1K"; // erase line
		std::cout << "\033[G";	// move cursor to beginning
		std::cout << '*';

		usleep(*t * 1000000);
	}
	return 0;
}