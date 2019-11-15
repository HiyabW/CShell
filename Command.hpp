#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

#include <iostream>
#include <cstring>
#include <string>
//#include "Connector.hpp"
//#include "Executable.hpp"
//#include "Prompt.hpp"

class Connector;
class Executable;

class Command {
     //protected:
     public:
        std::string name_com; //name of the connector
	//Executable* executable;
	//Argument* argument;
	//Connector* connector;
     //public:
	Command() { }
	
	virtual int run(Command*) = 0;
	//virtual 
};

#endif
