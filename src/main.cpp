#include <bits/stdc++.h>
#include <iomanip>
#include <string>

#include "math.h"

constexpr double GRAVITY = 9.8;
const int DELAY = 1000000;

/**
 * @brief prepares the terminal emulator for the simulation
 */
void setup()
{
	system("clear");				   // clear the console
	std::cout.setf(std::ios::unitbuf); // turn off stdout buffer
	std::cout.sync_with_stdio(false);
	std::cout << "\033[?25l"; // disable cursor blinking
	std::cout << "\033[0;1H"; // move cursor to [0][1]
}

// usage:
// 	- --help
// 	- rows
int main(int argc, char **argv)
{
	if (strcmp(argv[1], "--help") == 0)
	{
		std::cout << "Usage: freefall <distance>" << std::endl;
		return 0;
	}

	int d = std::stoi(argv[1]);
	auto vt = computeTime(d,
						  computeVelocity(GRAVITY, d));

	setup();
	for (auto t = vt.rbegin(); t != vt.rend(); ++t)
	{
		std::cout << "*";

		usleep(*t * DELAY);

		std::cout << "\b \b";  // erase rock
		std::cout << "\033[B"; // move cursor down
	}

	std::cout << "*";
	
	return 0;
}