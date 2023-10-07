/**
 * @file data_out.cpp
 * @author Zach Appella
 * @brief Exports calculations to a file using CSV
 * formatting.
 * @version 0.1
 * @date 2023-10-06
 * 
 * @copyright Copyright (c) 2023 Zach Appella
 * 
 * Licensed under the Creative Commons Attribution 1.0 Generic License.
 * You may obtain a copy of the License at:
 * https://creativecommons.org/licenses/by/1.0/
 */
#include <fstream>
#include <string>
#include <iostream>

#include "math.h"
#include "constants.h"

using namespace math;
using namespace constants;

// usage:
// - distance
// - outfile
int main(int argc, char** argv)
{
    if (argv[1] == "--help")
	{
		std::cout << "Usage: data_out <distance> <outfile>" << std::endl;
		return 0;
	}  
   
    int d = std::stoi(argv[1]);
	auto vt = computeTime(d,
						  computeVelocity(GRAVITY, d));
    
    std::ofstream out("out/" + std::string(argv[2]));
    for (int i = 0; i < vt.size(); ++i) {
        out << i << "," << vt[i] << "\n";
    }

    out.close();
    return 0;
}