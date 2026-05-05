#!/bin/bash

# Set exit on error
set -e

# Make build directory
mkdir -p build

# Compile
g++ -fdiagnostics-color=always -O3 src/saxpy.cpp -o build/saxpy

# Run 
timeout 0.5 build/saxpy
