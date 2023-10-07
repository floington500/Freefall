#!/bin/bash
#
# Checks if the required dependencies are installed
#
commands=("g++" "make" "git")

echo "Checking dependencies..."

for command in "${commands[@]}"
do
    if ! command -v "$command" &> /dev/null
    then
        echo "$command is not installed. Please install it."
        exit 1
    fi
done

echo "All dependencies are installed."
exit 0