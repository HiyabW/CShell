#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

#include <string>

class Command {
     protected:
        std::string name_com; //name of the connector
	//Executable* executable;
	//Argument* argument;
	//Connector* connector;
     public:
	Command() { }
	
	virtual int run() = 0;
	//virtual 
};

#endif
