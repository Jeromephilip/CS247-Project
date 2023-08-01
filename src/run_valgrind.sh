#!/bin/bash

# Function to run a single test
run_test() {
  test_file="$1"
  echo "Running test: $test_file"
  valgrind ./chess < "$test_file"
  echo "--------------------------------------"
}

# Function to run a specific test in the folder
run_specific_test() {
  folder="$1"
  test_filename="$2"
  test_file="$folder/$test_filename"
  
  if [ -f "$test_file" ]; then
    run_test "$test_file"
  else
    echo "Test file not found: $test_filename"
  fi
}

# Function to run all tests in a folder
if [ -z "$1" ]; then
  for test_file in "tests"/*.in; do
    run_test "$test_file"
  done
else
  # Run a specific test in the 'tests' folder
  run_specific_test "tests" "$1"
fi