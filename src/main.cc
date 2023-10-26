/**
 * @file main.cpp
 * @author Zach Appella
 * @brief Main file which contains the source code
 * for the freefall animation.
 * @version 0.1
 * @date 2023-10-06
 *
 * @copyright Copyright (c) 2023 Zach Appella
 *
 * Licensed under the Creative Commons Attribution 1.0 Generic License.
 * You may obtain a copy of the License at:
 * https://creativecommons.org/licenses/by/1.0/
 */
#include <bits/stdc++.h>
#include <iomanip>
#include <string>

#include "math.h"
#include "constants.h"

/**
 * @brief prepares the terminal emulator for the simulation.
 */
void setup()
{
	system("clear");				   // clear the console
	std::cout.setf(std::ios::unitbuf); // turn off stdout buffer
	std::cout.sync_with_stdio(false);
	std::cout << "\033[?25l"; // disable cursor blinking
}

void animate(int d, std::vector<double> &vt)
{
	// print the comparison column
	std::cout << "\033[0;2H"; // move cursor to [2][0] to print column
	for (int i = 0; i < d; ++i)
	{
		std::cout << "#";
		std::cout << "\033[B"; // move cursor down
		std::cout << "\b";	   // backspace
	}

	std::cout << "\033[0;1H"; // move cursor to starting position
	for (auto t = vt.rbegin(); t != vt.rend(); ++t)
	{
		std::cout << "*";

		usleep(*t * constants::DELAY);

		std::cout << "\b \b";  // erase rock
		std::cout << "\033[B"; // move cursor down
	}

	std::cout << "*"; // footer to make rock stay at bottom of screen
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

	int distance = std::stoi(argv[1]);
	auto time = math::computeTime(distance, math::computeVelocity(distance));

	setup();
	animate(distance, time);

	return 0;
}