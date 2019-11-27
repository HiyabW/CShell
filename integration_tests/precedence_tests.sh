#!/bin/sh
0<integration_tests/precedence_command.txt
&>integration_tests/precedence_output.txt
./rshell < integration_tests/precedence_command.txt >> integration_tests/precedence_output.txt
