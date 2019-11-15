#!/bin/sh
>exit_output.txt

g++ main_rshell.cpp Connector.cpp Executable.cpp -o exit.out

echo "run: exit"

./exit.out >> exit_output.txt

rm exit.out
