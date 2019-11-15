#!/bin/sh
>exit_output.txt

g++ ../src/main_rshell.cpp ../src/Connector.cpp ../src/Executable.cpp -o exit.out

echo "run: exit"

./exit.out >> exit_output.txt

rm exit.out
