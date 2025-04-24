#!/bin/zsh

# Check if file argument is provided
if [[ $# -eq 0 ]]; then
    echo "Usage: $0 <firmware.bin>"
    exit 1
fi

# Get the input file
INPUT_FILE=$1

# Check if file exists
if [[ ! -f $INPUT_FILE ]]; then
    echo "Error: File $INPUT_FILE not found"
    exit 1
fi

# Check if file ends with .bin
if [[ $INPUT_FILE != *.bin ]]; then
    echo "Error: Input file must be a .bin file"
    exit 1
fi

# Create output filename by replacing .bin with .uf2
OUTPUT_FILE=${INPUT_FILE%.bin}.uf2

# Path to uf2conv.py (relative to qmk_ydkb folder)
UF2CONV="uf2conv/uf2conv.py"

# Check if uf2conv.py exists
if [[ ! -f $UF2CONV ]]; then
    echo "Error: uf2conv.py not found in uf2conv/"
    exit 1
fi

# Convert bin to uf2
echo "Converting $INPUT_FILE to $OUTPUT_FILE..."
python3 $UF2CONV $INPUT_FILE -b 0x8004000 -c -f 0x9d5bcf10 -o $OUTPUT_FILE

# Check if conversion was successful
if [[ $? -eq 0 ]]; then
    echo "Conversion successful! Output file: $OUTPUT_FILE"
else
    echo "Error during conversion"
    exit 1
fi