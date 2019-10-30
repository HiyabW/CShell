# CS 100 Programming Project

## Project Information for CS100 RShell
* Fall 2019
* Hiyab Woldegebriel, SID 862098830 
* Ruth Navarrete, SID: 862106344

## Introduction
Utilizing Composite Pattern, develop a command shell called rshell in C++ which is capable of performing the following steps:

1. Print a command prompt (e.g. `$`)
1. Read in a line of command(s) (and connector(s)) from standard input
1. Execute the appropriate commands using fork, execvp, and waitpid

Commands will have the following format (note that the square brackets represent optional portions of an input):

`$ executable [argumentList] [connector] [executable] ...`

Where there can be any number of commands (which are composed of executables and argument lists) separated by either ||, && or ; which are the only valid connectors.

When executing a line of commands, you will need to account for the following requirements:

1. Execute the commands using the syscalls fork, execvp, and waitpid. Previous cs100 students created two video tutorials a fun cartoon tutorial as well as a more serious explanation, and should refer to the man pages for detailed instructions.
2. Every time you run a syscall, you must check for an error condition and if an error occurs then call perror. For examples on when, how, and why to use perror, see this video tutorial or the official man page.
3. You must have a special built-in command of exit which `exits` your program. This command should also adhere to the connector rules when deciding when/if it should be executed.
4. Anything that appears after a # character in the line should be considered a comment. For example, in the command `ls -lR` /, you would execute the program `/bin/ls` (performed using execvp) passing into it the parameters `-lR` and `/`. But in the command `ls # -lR /`, you would execute `/bin/ls`, but you would not pass any parameters because they appear in the comment section. You should also note that the # may or may not be followed by a space before the comment begins

## Diagram
![Image of Diagram](https://github.com/cs100/assignment-yabbie_ruth/blob/master/images/Design%20Assignment%20Diagram.png?raw=true)

## Classes
**Command**: Command is the component class. It has a `virtual int run() = 0` function that will be implemented by inhereited classes.

**Prompt:** Prompt is a compostite class. It will output the commmand prompt (e.g `$`) and then wait for user input. From the user input, it will parse through, determining what input will create what objects. For example, the first of the user input will always be an Execute. The next will then be checked if it is an argument or a connector and create an object of the corresponding class. It will have a vector of strings that will be used to check for valid arguments and a diffrent vector of valid connectors for comparison. If an argument or connector is not valid, it will output an error. If an argument or connector is valid, it will construct the corresponing object and push it onto another vector of Command*.

**Executable**: Executable is a leaf class. It will implement `virtual int run(Command*)` by calling `execvp(...)` on the passed in Command*. The `execvp(...)` will replace the current process with the process specified by the Command* parameter.

**Argument**: Argument is a component class. It will leave run as a pure virtual void. It will have classes that inherit from it. As of *(10/29/2019)*, we do not know what the inherited classes will be or how they will be implemented. these inhereited classes will implement `virtual int run(Command*)`.

**Connector**: Connector is a component class. It will leave `run(Command*)` as a pure virtual void. Inherited classes include operations such as conditional_both for the && connector, xor_connector for the || connetor, and and_connector for the ; connector. The inherited classes will implement `virtual int run(Command*)`. conditional_both will use the return from the previous Execute to determine if the next Execute will be run (if the previous Execute succeeds the next Execute will run). xor_connector will use the return of the previous Execute to determine if the next Execute will run (if the previous Execute fails, the next Execute will run). and_connector will run the next Execute regardless of the previous Execute's success.

## Development Roadmap
1. [ ] [Issue #1](https://github.com/cs100/assignment-yabbie_ruth/issues/1#issue-514387114) Create Command class
2. [ ] [Issue #2](https://github.com/cs100/assignment-yabbie_ruth/issues/2#issue-514392464) Create Prompt class
3. [ ] [Issue #3](https://github.com/cs100/assignment-yabbie_ruth/issues/3#issue-514394947) Test Prompt class
4. [ ] [Issue #4](https://github.com/cs100/assignment-yabbie_ruth/issues/4#issue-514395377) Create Execute class
5. [ ] [Issue #5](https://github.com/cs100/assignment-yabbie_ruth/issues/5#issue-514395582) Test Execute class
6. [ ] [Issue #6](https://github.com/cs100/assignment-yabbie_ruth/issues/6#issue-514395775) Create Argument class
  * there will be subclasses added to this class, current soecifications unknown
7. [ ] [Issue #7](https://github.com/cs100/assignment-yabbie_ruth/issues/7#issue-514395889) Test Argument class
8. [ ] [Issue #8](https://github.com/cs100/assignment-yabbie_ruth/issues/8#issue-514396213) Create Connector class
9. [ ] [Issue #9](https://github.com/cs100/assignment-yabbie_ruth/issues/9#issue-514396631) Create or_connector class
10. [ ] [Issue #12](https://github.com/cs100/assignment-yabbie_ruth/issues/12#issue-514396967) Test or_connector class
11. [ ] [Issue #10](https://github.com/cs100/assignment-yabbie_ruth/issues/10#issue-514396710) Create conditional_both class
12. [ ] [Issue #13](https://github.com/cs100/assignment-yabbie_ruth/issues/13#issue-514397036) Test conditional_both class
13. [ ] [Issue #11](https://github.com/cs100/assignment-yabbie_ruth/issues/11#issue-514396831) Create and_connector class
14. [ ] [Issue #14](https://github.com/cs100/assignment-yabbie_ruth/issues/14#issue-514397147) Test and_connector class
15. [ ] [Issue #15](https://github.com/cs100/assignment-yabbie_ruth/issues/15#issue-514397323) Test entire program
