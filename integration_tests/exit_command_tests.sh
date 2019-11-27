#!/bin/sh
0<integration_tests/exit_command.txt
:>integration_tests/exit_output.txt
./rshell < integration_tests/exit_command.txt >> integration_tests/exit_output.txt
