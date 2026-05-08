#!/bin/bash

set -euo pipefail


if [ $# -lt 1 ]; then
    echo "Usage: $0 /path/to/directory"
    exit 1
fi

DIRECTORY="$1"


if [ ! -d "$DIRECTORY" ]; then
    echo "Error: Directory does not exist."
    exit 1
fi

# Count files
TOTAL_FILES=$(find "$DIRECTORY" -type f | wc -l)

# Count directories
TOTAL_DIRS=$(find "$DIRECTORY" -type d | wc -l)

# Largest file
LARGEST_FILE=$(find "$DIRECTORY" -type f -exec ls -s {} + | sort -nr | head -n 1)

# Most recently modified file
RECENT_FILE=$(find "$DIRECTORY" -type f -printf '%T@ %p\n' | sort -nr | head -n 1 | cut -d' ' -f2-)

# Output
echo "Directory Statistics:"
echo "---------------------"
echo "Total files: $TOTAL_FILES"
echo "Total directories: $TOTAL_DIRS"

echo
echo "Largest file:"
echo "$LARGEST_FILE"

echo
echo "Most recently modified file:"
echo "$RECENT_FILE"