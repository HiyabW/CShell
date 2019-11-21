#ifndef __EXECUTABLE_HPP__
#define __EXECUTABLE_HPP__

#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysmacros.h>
#include "Command.hpp"

class Executable : public Command{
    public:
        char* args[100];
        Executable() { }
        virtual int run(Command*);
        char* get_exe() { return args[0]; }
};

#endif // __EXECUTABLE_HPP__ 
