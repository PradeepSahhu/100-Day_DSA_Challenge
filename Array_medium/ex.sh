
#!/bin/bash
echo "Made by Pradeep Sahu (22BCS10284)"
# Check if a filename is provided as a command-line argument
if [ "$#" -eq 0 ]; then
    echo "Usage: $0 <filename>"
    exit 1
fi

# Access the filename provided as the first command-line argument
filename="$1"
# Use basename to extract the filename without extension
file_without_extension=$(basename "$filename" | cut -d. -f1)

echo "Processing file: $filename"
# Your script logic goes here
g++ -std=c++11 $filename -o $file_without_extension && echo "compilation Done"

wait

./"$file_without_extension"
   
