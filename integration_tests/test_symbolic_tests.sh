#!/bin/sh
0<integration_tests/testS_command.txt
:>integration_tests/testS_output.txt
./rshell < integration_tests/testS_command.txt >> integration_tests/testS_output.txt
