#!/bin/bash
#
# Builds and then runs animation with
# specified distance arguements
#
if ! ./scripts/build.sh main; then
	echo -e "${red}error${clear} in building process"
	exit 1
fi

# run program
echo "Running program..."
sleep 2
./build/main $1
