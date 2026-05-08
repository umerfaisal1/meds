#!/bin/bash

set -euo pipefail

# Check arguments
if [ $# -ne 3 ]; then
    echo "Usage: $0 <prefix> <suffix> <directory>"
    exit 1
fi

PREFIX="$1"
SUFFIX="$2"
DIRECTORY="$3"

# Check directory exists
if [ ! -d "$DIRECTORY" ]; then
    echo "Error: Directory does not exist."
    exit 1
fi

# Counter for renamed files
COUNT=0

# Loop through matching files
for file in "$DIRECTORY"/"${PREFIX}"_old*.sv; do

    # Skip if no matching files exist
    [ -e "$file" ] || continue

    # Extract number N
    filename=$(basename "$file")

    number=$(echo "$filename" | sed -E "s/^${PREFIX}_old([0-9]+)\.sv$/\1/")

    # Validate extraction
    if [[ ! "$number" =~ ^[0-9]+$ ]]; then
        echo "Skipping invalid file: $filename"
        continue
    fi

    new_name="${SUFFIX}_new${number}.sv"

    # Rename file
    mv "$file" "$DIRECTORY/$new_name"

    echo "Renamed: $filename -> $new_name"

    COUNT=$((COUNT + 1))

done

# Check if any files were renamed
if [ "$COUNT" -eq 0 ]; then
    echo "No matching files found."
else
    echo "Successfully renamed $COUNT file(s)."
fi