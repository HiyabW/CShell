#!/bin/sh

: > ~/assignment-yabbie_ruth/integration_tests/commented_output.txt

echo "run: #"
./rshell >> ~/assignment-yabbie_ruth/integration_tests/commented_output.txt

echo "====="
echo "run: ls; echo hello #ls --all"
./rshell >> ~/assignment-yabbie_ruth/integration_tests/commented_output.txt

echo "====="
echo "run: echo \"hello && bye\"; ls # nope"
./rshell >> ~/assignment-yabbie_ruth/integration_tests/commented_output.txt
