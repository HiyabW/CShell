#!/bin/sh

: > ~/assignment-yabbie_ruth/integration_tests/single_output.txt


echo "run: ls -a"
./rshell >> ~/assignment-yabbie_ruth/integration_tests/single_output.txt

echo "====="
echo "run: mdir"
./rshell >> ~/assignment-yabbie_ruth/integration_tests/single_output.txt

echo "====="
echo "run: git"
./rshell >> ~/assignment-yabbie_ruth/integration_tests/single_output.txt

echo "====="
echo "run: git status"
./rshell >> ~/assignment-yabbie_ruth/integration_tests/single_output.txt
