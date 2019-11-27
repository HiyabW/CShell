#!/bin/sh
0<integration_tests/single_command.txt
:>integration_tests/single_output.txt
./rshell < integration_tests/single_command.txt >> integration_tests/single_output.txt
