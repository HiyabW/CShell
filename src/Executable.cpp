#ifndef __EXECUTABLE_CPP__
#define __EXECUTABLE_CPP__

#include "../header/Executable.hpp"

int Executable::run(Command* com) {
    std::string exit_str = "exit";
    char* exit_c = new char[exit_str.size() + 1];
    strcpy(exit_c, exit_str.c_str());

    std::string test_str = "test";
    char* test_c = new char[test_str.size() + 1];
    strcpy(test_c, test_str.c_str());

    std::string d_str = "-d";
    char* d_c = new char[d_str.size() + 1];
    strcpy(d_c, d_str.c_str());

    std::string f_str = "-f";
    char* f_c = new char[f_str.size() + 1];
    strcpy(f_c, f_str.c_str());

    std::string e_str = "-e";
    char* e_c = new char[e_str.size() + 1];
    strcpy(e_c, e_str.c_str());

    if ( !(strcmp(args[0], exit_c) ) ){
        return -2;
    }

    pid_t pid = fork();
    if(pid == -1) {
        perror("fork");
    }
    else if(pid == 0) { 
        if(!(strcmp(args[0], test_c) )) {
//std::cout << "ERROR CHECK: is git here?" << std::endl;	   
	   //std::cout << "successfully checked if executable was TEST" << std::endl;
	   struct stat sb;
           //std::cout << "successfully made stat" << std::endl;
	   if(!(strcmp(args[1], e_c) )) {
             stat(args[2], &sb);
	
	     if (S_ISREG(sb.st_mode)) {
               std::cout << "(TRUE)" << std::endl;
             }
             else if (S_ISDIR(sb.st_mode)) {
               std::cout << "(TRUE)" << std::endl;
             }
	     else {
                std::cout<<"(FALSE)" << std::endl;
		exit(EXIT_FAILURE);
             }
           }
           else if(!(strcmp(args[1], f_c) )) {
             stat(args[2], &sb);
             if (S_ISREG(sb.st_mode)) {
               std::cout << "(TRUE)" << std::endl;
             }
	     else {
                std::cout<<"(FALSE)" << std::endl;
		exit(EXIT_FAILURE);
             }
           }
	   else if(!(strcmp(args[1], d_c) )) {
             //std::cout << "in the -d if branch" << std::endl;
             stat(args[2], &sb);
             if (S_ISDIR(sb.st_mode)) {
               std::cout << "(TRUE)" << std::endl;
             }
	     else {
                std::cout<<"(FALSE)" << std::endl;
		exit(EXIT_FAILURE);
             }
           }
	   else {
            stat(args[1], &sb);
             if (S_ISREG(sb.st_mode)) {
               std::cout << "(TRUE)" << std::endl;
             }
             else if (S_ISDIR(sb.st_mode)) {
               std::cout << "(TRUE)" << std::endl;
             }
             else {
                std::cout<<"(FALSE)" << std::endl;
		exit(EXIT_FAILURE);
             }
           }
/* std::cout << "ret: 0" << std::endl; */
	  //return 0;
	  exit(0);
	}

     
        else if (execvp(args[0], args) == -1) { 
	    perror("execvp()");
            return 1;
        }
        else {
//NOTHING COUTS HERE
            return 0;
        }
    }
    else if(pid > 0) {
//std::cout << "ERROR CHECK: is git here?" << std::endl;
        int status = 0;
//std::cout << status << std::endl;
        if(waitpid(pid, &status, 0) == -1) {
//---git and ls dont make it to this cout statement---
//std::cout << "hello" << std::endl;
	    perror("wait");
            return 1;
        }
        else if (status != 0) {
//---git makes it here, ls doesnt---
//std::cout << status << std::endl;
            //return status;
	    if(WIFEXITED(status)) {
//std::cout << "git made it, ls didnt" << std::endl;
/* std::cout << "ret 0" << std::endl; */
		return 0;
            }
            else {
/* std::cout << "ret 1" << std::endl; */
	        return 1;
            }
        }
    } 
//std::cout << "ls" << std::endl;
/* std::cout << "ret: 1" << std::endl; */
    return 1;
}

#endif // __EXECUTABLE_CPP__
