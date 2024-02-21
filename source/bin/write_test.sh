#!/bin/bash

# List of commands to be executed
commands=(
    #Go to the source/bin directory
    "cd ./source"
    # Write unit tests 
    "g++ -o ./unittest/write_test ./unittest/write_test.cpp"
    "./unittest/write_test"
    "rm -r ./unittest/write_test"
    # Run the program
    "g++ -o ./code/main ./code/main.cpp ./code/study_in_pink1.cpp"
    "./code/main"
    "rm -r ./code/main"
    #out of source/bin
    "cd ../bin"
)

# Iterate over the commands and execute each one
for cmd in "${commands[@]}"; do
    echo "Executing: $cmd"
    eval "$cmd"
    if [ $? -eq 0 ]; then
        echo "Successfully!"
    else
        echo "Error executing command '$cmd'"
        exit 1
    fi
done

echo "All commands executed successfully"