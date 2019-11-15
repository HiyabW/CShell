#ifndef __EXECUTABLE_CPP__
#define __EXECUTABLE_CPP__

#include "../header/Executable.hpp"

int Executable::run(Command* com) {
	std::string exit_str = "exit";
	char* exit_c = new char[exit_str.size() + 1];
	strcpy(exit_c, exit_str.c_str());

	if ( !(strcmp(args[0], exit_c) ) ){
		exit(0);
	}

	pid_t pid = fork();
	if(pid == -1) {
		perror("fork");
	}
	else if(pid == 0) { 
		if (execvp(args[0], args) == -1) {
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
