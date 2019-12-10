#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

#include <iostream>
#include <cstring>
#include <string>
//#include <filesystem>

class Connector;
class Executable;
class Redirection;

class Command {
    private:
        //bool paren;
    public:
        Command() { }
        std::string name_com;
        virtual int run(Command*) = 0;
};

#endif // __COMMAND_HPP__
