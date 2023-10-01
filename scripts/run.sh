#!/bin/bash
#
if ! ./scripts/build.sh; then
	echo "error in building process"
	exit 1
fi

# run program
./build/freefall 15 10