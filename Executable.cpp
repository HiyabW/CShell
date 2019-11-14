#ifndef __EXECUTABLE_CPP__
#define __EXECUTABLE_CPP__

#include "Executable.hpp"

 
        int Executable::run(Command* com) {
           pid_t pid = fork();
 
           if(pid == -1) {
              perror("fork");
           }
 
           if(pid == 0) {
           
              if (execvp(args[0], args) == -1) {
                return -1;
              }
              else {
                return 0;
              }
           }
 
           if(pid > 0) {
              if(waitpid(pid-1, 0, 0) == -1) {
                perror("wait");
              }
              
           }
        return 0;
        }
 
 
#endif
