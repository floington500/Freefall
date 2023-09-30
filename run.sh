#!/bin/bash
#
if ! g++ main.cpp; then
	echo error in building process 
	exit 1
fi

# run program
./a.out 15 15 
