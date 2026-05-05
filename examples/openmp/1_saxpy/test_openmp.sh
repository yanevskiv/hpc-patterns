#!/bin/bash

# Set exit on error
set -e

# Create build directory
mkdir -p build

# Compile
g++ -Wall -O3 -fopenmp -fdiagnostics-color=always src/saxpy_openmp.cpp -o build/saxpy_openmp

# Run
build/saxpy_openmp
