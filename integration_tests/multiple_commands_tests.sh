#!/bin/sh
0<integration_tests/multiple_command.txt
:>integration_tests/multiple_output.txt
./rshell < integration_tests/multiple_command.txt >> integration_tests/multiple_output.txt
