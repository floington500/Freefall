/**
 * @file data_out.cpp
 * @author Zach Appella
 * @brief Exports calculations to a file using CSV
 * formatting.
 * @version 0.1
 * @date 2023-10-06
 * 
 */
#include <fstream>
#include <string>
#include <iostream>

#include "math.h"
#include "constants.h"

// usage:
// - distance
// - outfile
int main(int argc, char** argv)
{
    if (argv[1] == "--help")
	{
		std::cout << "Usage: freefall <distance>" << std::endl;
		return 0;
	}  
   
    int d = std::stoi(argv[1]);
	auto vt = computeTime(d,
						  computeVelocity(constants::GRAVITY, d));
    
    std::ofstream out("out/" + std::string(argv[2]));
    for (int i = 0; i < vt.size(); ++i) {
        out << i << "," << vt[i] << "\n";
    }

    out.close();
    return 0;
}