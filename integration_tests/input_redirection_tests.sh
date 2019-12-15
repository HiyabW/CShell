#!/bin/sh
0<integration_tests/input_command.txt
:>integration_tests/input_output.txt
./rshell < integration_tests/input_command.txt >> integration_tests/input_output.txt
