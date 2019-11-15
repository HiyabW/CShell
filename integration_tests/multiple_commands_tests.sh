#!/bin/sh

: > ~/assignment-yabbie_ruth/integration_tests/multiple_output.txt

echo "run: ls -a; mkdir || echo && echo \"h && g\"; git status"
./rshell >> ~/assignment-yabbie_ruth/integration_tests/multiple_output.txt

echo "====="
echo "run: git status || git"
./rshell >> ~/assignment-yabbie_ruth/integration_tests/multiple_output.txt

echo "====="
echo "run: echo hello && ls -a"
./rshell >> ~/assignment-yabbie_ruth/integration_tests/multiple_output.txt

echo "====="
echo "run: git; git status"
./rshell >> ~/assignment-yabbie_ruth/integration_tests/multiple_output.txt

echo "====="
echo "run: git; add && ls || ls -a #exit"
./rshell >> ~/assignment-yabbie_ruth/integration_tests/multiple_output.txt
