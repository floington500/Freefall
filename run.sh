#!/bin/bash
#
if ! g++ src/main.cpp -o build/freefall.out; then
	echo error in building process 
	exit 1
fi

# run program
./build/freefall.out 15 10