#!/bin/sh

: > ~/assignment-yabbie_ruth/integration_tests/exit_output.txt

echo "run : exit"
./rshell >> ~/assignment-yabbie_ruth/integration_tests/exit_output.txt

echo "====="
echo "run: ls && exit || ls"
./rshell >> ~/assignment-yabbie_ruth/integration_tests/exit_output.txt

echo "====="
echo "run: ls; mkdir && exit ||  exit"
./rshell >> ~/assignment-yabbie_ruth/integration_tests/exit_output.txt
