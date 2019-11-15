#!/bin/sh
> comment_output.txt

g++ ../src/main_rshell.cpp ../src/Connector.cpp ../src/Executable.cpp -o comment.out

echo "run: ls -a; mkdir no || echo && echo \"h && g\"; git status #ls --all; exit"
echo "exit"

./comment.out >> comment_output.txt

rm comment.out
