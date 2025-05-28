#!/bin/bash

parallel "g++ -O{} Fibonacci.cpp -o Fibonacci_O{}.x && ./Fibonacci_O{}.x 40 > datos_{}.txt" ::: 0 1 2 3 fast
