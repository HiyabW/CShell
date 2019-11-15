#!/bin/sh

>single_output.txt

g++ main_rshell.cpp Connector.cpp Executable.cpp -o single.out
echo "run: ls -a; exit"
./single.out >> single_output.txt


rm single.out
