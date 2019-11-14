#ifndef __EXECUTABLE_CPP__
#define __EXECUTABLE_CPP__

#include "Executable.hpp"

int Executable::run(Command* com) {
	std::cout << "in Executable run()" << std::endl;
	pid_t pid = fork();
	if(pid == -1) {
		perror("fork");
	}
	else if(pid == 0) {
		std::cout << "in child" << std::endl;
		if (execvp(args[0], args) == -1) {
			std::cout << "exec failed" << std::endl;
			return -1;
		}
		else {
			return 0;
		}
	}
	else if(pid > 0) {
		std::cout << "in parent waiting" << std::endl;
		if(waitpid(pid, 0, 0) == -1) {
			perror("wait");
		}
		std::cout << "parent received child" << std::endl;
	}
	return 0;
}
 
 
#endif
