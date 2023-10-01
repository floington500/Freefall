#!/bin/bash
#
g++ -c src/main.cpp -Iinclude -o build/main.o
g++ -c src/math.cpp -Iinclude -o build/math.o

g++ build/main.o build/math.o -o build/freefall
