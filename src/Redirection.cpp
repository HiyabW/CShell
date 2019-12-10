#ifndef __REDI_CPP__
#define __REDI_CPP__

#include "../header/Redirection.hpp"
#include <stdio.h>

char* Redirection::get_first(int i) {
    return arguments[i]; 
}

int Redirection::run(Command* c) {
    
std::cout << "Made it to RediRun call" << std::endl;
    std::string input_str = "<";
    char* input_c = new char[input_str.size() + 1];
    strcpy(input_c, input_str.c_str());

    std::string overwrite_str = ">";
    char* overwrite_c = new char[overwrite_str.size() + 1];
    strcpy(overwrite_c, overwrite_str.c_str());

    std::string cat_str = ">>";
    char* cat_c = new char[cat_str.size() + 1];
    strcpy(cat_c, cat_str.c_str());

    std::string pipe_str = "|";
    char* pipe_c = new char[pipe_str.size() + 1];
    strcpy(pipe_c, pipe_str.c_str());
  
  unsigned i = 0;
  while (arguments[i] != NULL) {
        if(!(strcmp(arguments[i], input_c)) ) {
           this->input_run(i);
        }

        else if( !(strcmp(arguments[i], overwrite_c)) ) {
           this->overwrite_run(i);
std::cout << "Made it to overwrite_run call" << std::endl;
        }

        else if ( !(strcmp(arguments[i], cat_c)) ) {
           this->cat_run(i);
        }

        else if( !(strcmp(arguments[i], pipe_c)) ) {
           this->pipe_run(i);
        }

        else {
           std::cout<< "ERROR: Invalid redirection symbol" << std::endl;
           return -1;
        }
        ++i;
   }
   return 0;
}

/* int Redirection::input_run(int i) {
   ++i;
   int result = args[i]->run(i);
   if(result == 1) {
     std::cout << "ERROR: Invalid Executable" << std::endl;
     exit(1);
   }
}
*/

int  Redirection::input_run(int i) {
	return 0;
}

int Redirection::cat_run(int i) {
	return 0;
}

int Redirection::pipe_run(int i) {
	return 0;
}

int Redirection::overwrite_run(int i) {
std::cout << "In overwrite_run call" << std::endl;
   ++i;
   pid_t pid = fork();
   close(1);
   int file_desc = open(arguments[i+1], O_WRONLY);

    if(file_desc < 0) {
        printf("Error opening the file\n");
    }

    int copy_desc = dup(file_desc);

    if(pid == -1) {
        perror("fork");
    }

    else if(pid == 0) {
       if (execvp(arguments[i], arguments) == -1) {
           perror("execvp()");
           return 1;
std::cout << "Successful execvp() call" << std::endl;
       }
       else {
          return 0;
       }
    }

    else if(pid > 0) {
       int status = 0;
       if(waitpid(pid, &status, 0) == -1) {
          perror("wait");
            return 1;
        }
        else if (status != 0) {
          if(WIFEXITED(status)) {
               return 0;
          }
          else {
              return 1;
          }
        }
    }
 return 1; 
}

#endif
