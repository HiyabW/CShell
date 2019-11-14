#ifndef __EXECUTABLE_CPP__
#define __EXECUTABLE_CPP__

#include "Executable.hpp"

int Executable::run(Command* com) {
	std::string exit = "exit";
	char* exit_c = new char[exit.size() + 1];
	strcpy(exit_c, exit.c_str());

	pid_t pid = fork();
	if(pid == -1) {
		perror("fork");
	}
	else if(pid == 0) { 
		if ( !(strcmp(args[0], exit_c) ) ){
			return -2;
		}
		else if (execvp(args[0], args) == -1) {
			perror("execvp()");
			return -1;
		}
		else {
			return 0;
		}
	}
	else if(pid > 0) {
                int status = 0;
		if(waitpid(pid, &status, 0) == -1) {
			perror("wait");
		}
                if (status != 0) {
                    return status;
          	}
	}
	return 1;
}
 
 
#endif
