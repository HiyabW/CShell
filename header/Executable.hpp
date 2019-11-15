#ifndef __EXECUTABLE_HPP__
#define __EXECUTABLE_HPP__

#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

#include "Command.hpp"

class Executable : public Command{
	public:
		char* args[100];
		Executable() { }
		virtual int run(Command*);
};

#endif  
