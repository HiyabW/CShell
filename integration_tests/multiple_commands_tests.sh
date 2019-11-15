#!/bin/sh
>multiple_output.txt

g++ ../src/main_rshell.cpp ../src/Connector.cpp ../src/Executable.cpp -o multiple.out
echo "run: ls -a; mkdir no || echo && echo \"h && g\"; git status; exit"
./multiple.out >> multiple_output.txt

rm multiple.out
