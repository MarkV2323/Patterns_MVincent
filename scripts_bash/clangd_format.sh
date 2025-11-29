#!/bin/bash

# Check for required argument
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <directory>"
    exit 1
fi

DIR="$1"

# Verify that the directory exists
if [ ! -d "$DIR" ]; then
    echo "Error: '$DIR' is not a directory"
    exit 1
fi

# Find all C/C++ source files and format them
find "$DIR" -type f \( -name "*.cpp" -o -name "*.cc" -o -name "*.hpp" -o -name "*.c" -o -name "*.h" \) | while read -r file; do
    echo "Formatting $file"
    clang-format -i "$file"  # -i = edit file in-place
done

echo "Formatting complete!"
