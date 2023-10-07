#!/bin/bash
#
# ENTER PROGRAM NAME TO BUILD LIKE SO:
# ./build.sh <target>
#
program_name=$1
obj="${program_name}.o"

g++ -c "src/${program_name}.cpp" -Iinclude -o "build/${obj}"
g++ -c src/math.cpp -Iinclude -o build/math.o

g++ "build/${obj}" build/math.o -o "build/${program_name}"