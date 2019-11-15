#!/bin/sh

>single_output.txt

g++ ../src/main_rshell.cpp ../src/Connector.cpp ../src/Executable.cpp -o single.out
echo "run: ls -a; exit"
./single.out >> single_output.txt


rm single.out
