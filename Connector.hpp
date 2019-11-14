#ifndef __CONNECTOR_HPP__
#define __CONNECTOR_HPP__

#include <iostream>
#include "Command.hpp"
#include "Executable.hpp"
#include <vector>

class Connector : public Command {
     protected:
           void parse();
	   int execCount;
           int argCount;
           int conCount;
     public: 
	   std::vector<Command*> myCommands;
	   int result;
	   std::string connector; 
     //public:
	Connector() {}
	
	virtual int run(Command*);

	void and_connector(Command*);
	
	void or_connector(Command*);

	void conditional_both(Command*);

        int get_exec() { return execCount; }
        int get_arg() { return argCount; }
        int get_con() { return conCount; }
};
	
#endif	
	
