#!/bin/bash

set -euo pipefail

if [ $# -lt 1 ]; then
    echo "Usage: $0 /path/to/folder"
    exit 1
fi

DIRECTORY="$1"
echo $DIRECTORY

# Create folders
mkdir -p "$DIRECTORY/verilog"
mkdir -p "$DIRECTORY/code"
mkdir -p "$DIRECTORY/docs"

# Move .v files
for file in "$DIRECTORY"/*.v; do
    [ -e "$file" ] || continue
    mv "$file" "$DIRECTORY/verilog/"
done

# Move .c files
for file in "$DIRECTORY"/*.c; do
    [ -e "$file" ] || continue
    mv "$file" "$DIRECTORY/code/"
done

# Move .txt files
for file in "$DIRECTORY"/*.txt; do
    [ -e "$file" ] || continue
    mv "$file" "$DIRECTORY/docs/"
done

echo "Files organized successfully."