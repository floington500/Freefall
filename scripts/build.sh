#!/bin/bash
#
# ENTER PROGRAM NAME TO BUILD LIKE SO:
# ./build.sh <target>
#
program_name=$1
obj="${program_name}.o"
green="\033[0;32m"
red="\033[0;31m"
clear="\033[0m"

g++ -c "src/${program_name}.cc" -Iinclude -o "build/${obj}"
g++ -c src/math.cc -Iinclude -o build/math.o

g++ "build/${obj}" build/math.o -o "build/${program_name}"
echo -e "The build process was executed ${green}successfully${clear}!"
sleep 2
