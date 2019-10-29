# CS 100 Programming Project

## Project Information for CS100 RShell
Hiyab Woldegebriel, SID 862098830
Ruth Navarrete, SID: 862106344
Fall 2019

## Introduction
Utilizing Composite Pattern, develop a command shell called rshell in C++ which is capable of performing the following steps:

1. Print a command prompt (e.g. `$`)
1. Read in a line of command(s) (and connector(s)) from standard input
1. Execute the appropriate commands using fork, execvp, and waitpid

Commands will have the following format (note that the square brackets represent optional portions of an input):

$ executable [argumentList] [connector] [executable] ...

Where there can be any number of commands (which are composed of executables and argument lists) separated by either ||, && or ; which are the only valid connectors.

When executing a line of commands, you will need to account for the following requirements:

1. Execute the commands using the syscalls fork, execvp, and waitpid. Previous cs100 students created two video tutorials a fun cartoon tutorial as well as a more serious explanation, and should refer to the man pages for detailed instructions.
1. Every time you run a syscall, you must check for an error condition and if an error occurs then call perror. For examples on when, how, and why to use perror, see this video tutorial or the official man page.
1. You must have a special built-in command of exit which exits your program. This command should also adhere to the connector rules when deciding when/if it should be executed.
1. Anything that appears after a # character in the line should be considered a comment. For example, in the command ls -lR /, you would execute the program /bin/ls (performed using execvp) passing into it the parameters -lR and /. But in the command ls # -lR /, you would execute /bin/ls, but you would not pass any parameters because they appear in the comment section. You should also note that the # may or may not be followed by a space before the comment begins

## Diagram

## Classes
**Executable**: The executable is similar to a.out or ./test in the previous assignments. We use this file to run/test our code.
**Argument_List**: Argument_Lists are lists of 0  or more arguments. Note that arguments surrounded by quotation marks are still valid and should compile the same way as if they didnt've have them.

**Connector**: Connectors include operations such as && and ||.
