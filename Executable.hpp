#ifndef __EXECUTABLE_HPP__
#define __EXECUTABLE_HPP__

#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

#include "Command.h"

class Executable{
     private:
	char* args[100];
     public:
	Executable() {}

	virtual int run(Command* com) {
	   pid_t pid = fork();

	   if(pid == -1) {
	      perror("fork");
	   }
  
	   if(pid == 0) {
	   //child
	      if (execvp(args[0], args) == -1) {
		return -1;
	      }
	      else {
	        return 0;
	      }
	   }

	   if(pid > 0) {
	      if(waitpid(pid-1, 0) == -1) {
		perror("wait");
	      }
	      //parent
	   }
	return 0;
	}
	 
};

#endif  
