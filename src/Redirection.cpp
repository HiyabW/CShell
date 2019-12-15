#ifndef __REDI_CPP__
#define __REDI_CPP__

#include "../header/Redirection.hpp"
#include <stdio.h>

int Redirection::run(Command* c) {
    
//std::cout << "Made it to RediRun call" << std::endl;
    
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
 

//printf("REDI COM: %s\n", arguments[0]);
  unsigned i = 0;
  while (arguments[i] != NULL) {
     //std::cout << arguments[i] << " " << arguments[i+1] << " " << arguments[i+2] << " ---->" << arguments[3] << std::endl;
     int j = i+1, k = 0;
     char* rediSubArgs[1000]; 
           
           if( !(strcmp(arguments[i], input_c)) ) {
              while(arguments[j] != NULL  && ((strcmp(arguments[j], input_c) != 0) || (strcmp(arguments[j], overwrite_c) != 0) || (strcmp(arguments[j], cat_c) != 0) || (strcmp(arguments[j], pipe_c) != 0))) {
                 if(arguments[j] == NULL) {
                   std::cout << "reached the null, shouldn't make it here!" << std::endl;
                 }
                 rediSubArgs[k] = arguments[j];
                 ++j; ++k;
             }
             rediSubArgs[k-1] = NULL;
             int result = this->input_run(j, arguments, rediSubArgs);
             if(result == 1) {
                return 1;
             }
	    }
           

           else if( !(strcmp(arguments[i], overwrite_c)) ) { 
              while(arguments[j] != NULL  && ((strcmp(arguments[j], input_c) != 0) || (strcmp(arguments[j], overwrite_c) != 0) || (strcmp(arguments[j], cat_c) != 0) || (strcmp(arguments[j], pipe_c) != 0))) {
                 if(arguments[j] == NULL) {
                   std::cout << "reached the null, shouldn't make it here!" << std::endl;
                 }
                 rediSubArgs[k] = arguments[j];
	 	 ++j; ++k;
             }
             rediSubArgs[k-1] = NULL; 
             int result = this->overwrite_run(j, arguments, rediSubArgs);
	     if(result == 1) {
        	return 1;
             }
          }

           else if ( !(strcmp(arguments[i], cat_c)) ) {
              while(arguments[j] != NULL  && ((strcmp(arguments[j], input_c) != 0) || (strcmp(arguments[j], overwrite_c) != 0) || (strcmp(arguments[j], cat_c) != 0) || (strcmp(arguments[j], pipe_c) != 0))) {                
                 if(arguments[j] == NULL) {
                   std::cout << "reached the null, shouldn't make it here!" << std::endl;
                 }
                 rediSubArgs[k] = arguments[j];
                 ++j; ++k;
             }
             rediSubArgs[k-1] = NULL; 
             int result = this->cat_run(j, arguments, rediSubArgs);
             if(result == 1) {
                return 1;
             }
 	    }

           else if( !(strcmp(arguments[i], pipe_c)) ) {
              this->pipe_run(i);
           }

       /*    else {
              std::cout<< "ERROR: Invalid redirection symbol" << std::endl;
              return -1;
           }
       */ 
      ++i;
     }
 return 1;  
}

int  Redirection::input_run(int j, char* arguments[], char* rediSubArgs[]) {
   int file_desc = open(arguments[j-1], O_RDONLY);
   if(file_desc < 0) {
        printf("Error opening the file\n");
    }

    pid_t pid = fork();
    if(pid == -1) {
        perror("fork");
    }

    else if(pid == 0) {
    dup2(file_desc, 0);
    close(file_desc);
       if (execvp(rediSubArgs[0], rediSubArgs) == -1) {
          perror("execvp()");
           exit(1);
       }
       else {
         exit(0);
       }
    }

    else if(pid > 0) {
       int status = 0;
       if(waitpid(pid, &status, 0) == -1) {
          perror("wait");
            exit(1);
        }
        else if (status != 0) {
          if(WIFEXITED(status)) {
               exit(0);
          }
          else {
              exit(1);
          }
        }
    }

 return 1;
}

int Redirection::cat_run(int j, char* arguments[], char* rediSubArgs[]) {
   int file_desc = open(arguments[j-1], O_WRONLY | O_CREAT | O_APPEND);
   if(file_desc < 0) {
        printf("Error opening the file\n");
    }

    pid_t pid = fork();
    if(pid == -1) {
        perror("fork");
    }

    else if(pid == 0) {
    dup2(file_desc, 1);
    close(file_desc);
       if (execvp(rediSubArgs[0], rediSubArgs) == -1) {
          perror("execvp()");
           exit(1);
       }
       else {
         return 0;
       }
    }

    else if(pid > 0) {
       int status = 0;
       if(waitpid(pid, &status, 0) == -1) {
          perror("wait");
            exit(1);
        }
        else if (status != 0) {
          if(WIFEXITED(status)) {
               return 0;
          }
          else {
              exit(1);
          }
        }
    }

 return 1;
}

int Redirection::pipe_run(int i) {
	return 0;
}

int Redirection::overwrite_run(int j, char* arguments[], char* rediSubArgs[]) {
     int file_desc = open(arguments[j-1], O_WRONLY | O_CREAT | O_TRUNC);
   if(file_desc < 0) {
        printf("Error opening the file\n");
    }

    pid_t pid = fork();
    if(pid == -1) {
        perror("fork");
    }

    else if(pid == 0) {
    dup2(file_desc, 1);
    close(file_desc);
       if (execvp(rediSubArgs[0], rediSubArgs) == -1) {
          perror("execvp()");
           exit(1);
       }
       else {
         return 0;
       }
    }

    else if(pid > 0) {
       int status = 0;
       if(waitpid(pid, &status, 0) == -1) {
          perror("wait");
            exit(1);
        }
        else if (status != 0) {
          if(WIFEXITED(status)) {
               exit(0);
          }
          else {
              exit(1);
          }
        }
    }

 return 1; 
}

#endif
