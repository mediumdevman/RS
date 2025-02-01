#!/bin/bash

# Get the script's directory (where run.sh is located)
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Change to that directory
cd "$SCRIPT_DIR" || { echo "Error: Cannot change to directory $SCRIPT_DIR"; exit 1; }

# Run the executable
./run master.csv

exit 0