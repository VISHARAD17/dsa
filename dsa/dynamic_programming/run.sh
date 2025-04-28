#!/bin/bash

# Check if a C++ filename is provided as an argument
if [ -z "$1" ]; then
    echo "Usage: bash $0 <cpp_file>"
    exit 1
fi

# Compile the provided C++ file to the default output binary a.out
g++ -std=c++23 "$1"
if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

# Execute the compiled program (a.out)
./a.out
