#ifndef PROMPT_HPP
#define PROMPT_HPP

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include "Command.hpp"
#include "Executable.hpp"
#include "Connector.hpp"

class Connector;

class Prompt : public Command {
    //protected:
    public:
        void parse(Connector*);
        int execCount;
        int argCount;
        int conCount;
    //public:
        Prompt() : Command() { }
        virtual int run (Connector*);
};
#endif // PROMPT_HPP
