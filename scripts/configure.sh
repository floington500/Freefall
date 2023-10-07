#!/bin/bash
#
# Checks if the required dependencies are installed
# and then builds the selected program.
#
# USAGE: ./configure.sh <target>
#
commands=("g++" "make" "git")
green="\033[0;32m"
red="\033[0;31m"
clear="\033[0m"

echo "Checking dependencies..."

for command in "${commands[@]}"
do
    if ! command -v "$command" &> /dev/null
    then
        echo "Unresolved dependency: ${red}$command${clear}"
        exit 1
    fi
done

echo "All dependencies are installed."
sleep 2

program_name=$1
echo "Building ${program_name}..."
if ! make ${program_name}; then
    echo -e "${red}Error${clear} in building process"
    exit 1
fi

echo -e "The build process was executed ${green}successfully${clear}!"
sleep 2

exit 0