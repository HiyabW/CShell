#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

#include <iostream>
#include <cstring>
#include <string>

class Connector;
class Executable;

class Command {
    public:
        Command() { }
        std::string name_com;
        virtual int run(Command*) = 0;
};

#endif // __COMMAND_HPP__
