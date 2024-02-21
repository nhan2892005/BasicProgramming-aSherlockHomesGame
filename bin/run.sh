#!/bin/bash

# List of commands to be executed
commands=(
    # Write test
    "cd ./bin"
    # Run program
    "g++ -o ../initial/main ../initial/main.cpp ../submission/study_in_pink1.cpp"
    "../initial/main"
    "rm -r ../initial/main"
    # Compare results and tests
    "./compare.sh ../result/list_output ../source/unittest/list_output_test"
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
