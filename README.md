# Command Shell C++, CS100 UCR

## Description
This project implements system calls as well as composite pattern & high level C++ to ultimately create a Command Shell capable of preforming popular linux commands such as ls, test -d/-f, etc. A more detailed description of the project can be found below.

I completed this project with one other partner in approximately 10 weeks as a requirement for my CS100 class.

## Introduction
Utilizing Composite Pattern, develop a command shell called rshell in C++ which is capable of performing the following steps:

1. Print a command prompt (e.g. `$`)
1. Read in a line of command(s) (and connector(s)) from standard input
1. Execute the appropriate commands using `fork`, `execvp`, and `waitpid`

Commands will have the following format (note that the square brackets represent optional portions of an input):

`$ executable [argumentList] [connector] [executable] ...`

Where there can be any number of commands (which are composed of executables and argument lists) separated by either ||, && or ; which are the only valid connectors.

When executing a line of commands, you will need to account for the following requirements:

1. Execute the commands using the syscalls fork, execvp, and waitpid. Previous cs100 students created two video tutorials a fun cartoon tutorial as well as a more serious explanation, and should refer to the man pages for detailed instructions.
2. Every time you run a syscall, you must check for an error condition and if an error occurs then call perror. For examples on when, how, and why to use perror, see this video tutorial or the official man page.
3. You must have a special built-in command of `exit` which exits your program. This command should also adhere to the connector rules when deciding when/if it should be executed.
4. Anything that appears after a # character in the line should be considered a comment. For example, in the command `ls -lR` /, you would execute the program `/bin/ls` (performed using execvp) passing into it the parameters `-lR` and `/`. But in the command `ls # -lR /`, you would execute `/bin/ls`, but you would not pass any parameters because they appear in the comment section. You should also note that the # may or may not be followed by a space before the comment begins

## Diagram
![Image of Diagram](https://github.com/cs100/assignment-yabbie_ruth/blob/master/images/Assignment%203%20Design%20Assignment%20Diagram.png?raw=true)

## Classes
**Command**: Command is the component class. It has a `virtual int run(Command*) = 0` function that will be implemented by inhereited classes. It also has a string name_com that is mainly utilized by the Connector class.

**Executable**: Executable is a leaf class. It will implement `virtual int run(Command*)` by first forking and then calling `execvp(...)` on the process child. The `execvp(...)` will replace the current process with the process specified by the Command* parameter. It has a few specific cases such as `exit` and `test` that it does special behavior for. Running the exit executable should take the user out of the terminal loop and ultimately terminate the shell, while the test executable takes in a file path and determines whether its argument is a correct file (-f flag) or correct directory (-d flag). The -e flag checks if the argument is either a correct file or directory, and if no flag is specified, the -e flag should be the default. The test executable may also be written using [] instead of the literal word "test", and must work for both relative and absolute file paths. 

**Note for unit testing run() in Executable** Unit testing for `Executable::run()` uses `Connector::parse()`, which requires user input as we are testing user input and are not redirecting input from a file or other.

**Connector**: Connector is a composite class. First, it will output the commmand prompt (e.g `$`) and then wait for user input. From the user input, it will parse through, determining what input will create what objects. For example, if first of the user input is an Executable, it will then take in any arguments up until a connector and create an Executable. Once a connector is encountered in the user input, the Executable will be pushed onto a vector of Command* and then a Connector will be created and pushed onto the same vector. The populated vetor is in the pattern of executable, connector, executable... so on so forth. 

In terms of implementing the `run(Command*)` function, Connector calls run on an executable, and depending on the result given by `execvp` as well as the current connector, will iterate through the vector of Command* (executable, connector, executable...) and call either the functions conditional_both for the && connector, xor_connector for the || connetor, and and_connector for the ; connector. These mentioned functions will also implement `virtual int run(Command*)` by calling run on each individual executable and actually executing it. Conditional_both will use the return from the previous Executable to determine if the next Executable will be run (if the previous Executable succeeds the next Executable will run). Xor_connector will use the return of the previous Execuable to determine if the next Executable will run (if the previous Executable fails, the next Executable will run). And_connector will run the next Executable regardless of the success previous Executable.

The Connector class will continue to loop for prompting until `exit` is entered.

**Note for unit testing parse() in Connector** Unit testing for parse() requires user input as we are testing user input and are not redirecting input from a file or other.

**Redirection**: Redirection handles the IO Redirection commands <, >, and >>. It has its own separate parsing method in the Connector class where a new Redirection object is made and is parsed accordingly such that the array of arguments for the new object begins with the first element being either <, >, or >>. The next element is the executable (cat, echo, etc), and the next few elements are the executables arguments. Finally, the array is terminated with null. Then, we take this redirection object with its populated array and push it onto the myCommands vector, where it is parsed and ran as normal. To run a redirection object, some helpful functions to use include dup2(), open(), and close. Sufficient understanding of file descriptors are essential to this portion of the project.

## Development Roadmap
1. [ ] [Issue #1](https://github.com/cs100/assignment-yabbie_ruth/issues/1) Create Command class
2. [ ] [Issue #2](https://github.com/cs100/assignment-yabbie_ruth/issues/2) Create parsing function
3. [ ] [Issue #3](https://github.com/cs100/assignment-yabbie_ruth/issues/3) Test parsing function
4. [ ] [Issue #4](https://github.com/cs100/assignment-yabbie_ruth/issues/4) Create Executable class
5. [ ] [Issue #5](https://github.com/cs100/assignment-yabbie_ruth/issues/5) Test Executable class
6. [ ] [Issue #6](https://github.com/cs100/assignment-yabbie_ruth/issues/6) Create Argument class [__NO LONGER AN ISSUE THAT NEEDS TO BE ADDRESSES__]
  * there will be subclasses added to this class, current soecifications unknown [__NO LONGER AN ISSUE THAT NEEDS TO BE ADDRESSES__]
7. [ ] [Issue #7](https://github.com/cs100/assignment-yabbie_ruth/issues/7) Test Argument class [__NO LONGER AN ISSUE THAT NEEDS TO BE ADDRESSES__]
8. [ ] [Issue #8](https://github.com/cs100/assignment-yabbie_ruth/issues/8) Create Connector class
9. [ ] [Issue #9](https://github.com/cs100/assignment-yabbie_ruth/issues/9) Create or_connector class
10. [ ] [Issue #12](https://github.com/cs100/assignment-yabbie_ruth/issues/12) Test or_connector class
11. [ ] [Issue #10](https://github.com/cs100/assignment-yabbie_ruth/issues/10) Create conditional_both class
12. [ ] [Issue #13](https://github.com/cs100/assignment-yabbie_ruth/issues/13) Test conditional_both class
13. [ ] [Issue #11](https://github.com/cs100/assignment-yabbie_ruth/issues/11) Create and_connector class
14. [ ] [Issue #14](https://github.com/cs100/assignment-yabbie_ruth/issues/14) Test and_connector class
15. [ ] [Issue #15](https://github.com/cs100/assignment-yabbie_ruth/issues/15) Test entire program
  *  __ISSUES 16 TRHOUGH 19 WERE PULL REQUESTS__
20. [ ] [Issue #20](https://github.com/cs100/assignment-yabbie_ruth/issues/20) Implement test implementation/parsing in parsing function
21. [ ] [Issue #21](https://github.com/cs100/assignment-yabbie_ruth/issues/21) Test test in parsing function
22. [ ] [Issue #22](https://github.com/cs100/assignment-yabbie_ruth/issues/22) Test test in Execuatable
27. [ ] [Issue #27](https://github.com/cs100/assignment-yabbie_ruth/issues/27) Implement parentheses implementation/parsing in parsing function
23. [ ] [Issue #23](https://github.com/cs100/assignment-yabbie_ruth/issues/23) Test parentheses implementation in parsing function
24. [ ] [Issue #24](https://github.com/cs100/assignment-yabbie_ruth/issues/24) Test parentheses in Connector
25. [ ] [Issue #25](https://github.com/cs100/assignment-yabbie_ruth/issues/25) Update integration tests
26. [ ] [Issue #26](https://github.com/cs100/assignment-yabbie_ruth/issues/26) Update unit tests if we need more
27. [ ] [Issue #27](https://github.com/cs100/assignment-yabbie_ruth/issues/26) Test to see if input redirection works accordingly
28. [ ] [Issue #28](https://github.com/cs100/assignment-yabbie_ruth/issues/26) Test to see if output redirection works accordingly (non append)
29. [ ] [Issue #29](https://github.com/cs100/assignment-yabbie_ruth/issues/26) Test to see if input redirection works accordingly (append)
30. [ ] [Issue #30](https://github.com/cs100/assignment-yabbie_ruth/issues/26) Ensure integration and unit tests function appropriately
