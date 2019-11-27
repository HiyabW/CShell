#!/bin/sh
0<integration_tests/testL_command.txt
&>integration_tests/testL_output.txt
./rshell < integration_tests/testL_command.txt >> integration_tests/testL_output.txt
