#ifndef __CONNECTOR_HPP__
#define __CONNECTOR_HPP__

#include <iostream>
#include "Command.hpp"
#include "Executable.hpp"
#include <vector>
#include <cstring>
#include <algorithm>
#include <iterator>

class Connector : public Command {
    protected:
        Connector* ParenParse(char*);
        int execCount;
        int argCount;
        int conCount;
        int and_connector(Command*);
        int or_connector(Command*);
        int conditional_both(Command*);
        std::vector<Command*> myCommands;
        int result;
        std::string connector; 
bool paren;
    public:
        Connector() {
             paren = false;
             result = 1;
        }
        virtual int run(Command*);
        void parse();
        int get_exec() { return execCount; }
        int get_arg() { return argCount; }
        int get_con() { return conCount; }
};
	
#endif // __CONNECTOR_HPP__	
