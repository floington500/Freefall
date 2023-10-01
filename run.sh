#!/bin/bash
#
if ! g++ main.cpp -o freefall.out; then
	echo error in building process 
	exit 1
fi

# run program
./freefall.out 15 15