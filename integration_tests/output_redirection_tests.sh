#!/bin/sh
0<integration_tests/output_command.txt
:>integration_tests/output_output.txt
./rshell < integration_tests/output_command.txt >> integration_tests/output_output.txt
