#ifndef __REDI_HPP__
#define __REDI_HPP__

#include <iostream>
#include <vector>
#include "Command.hpp"

class Redirection : public Command {
    protected:
        int input_run();
        int overwrite_run();
        int cat_run();
        int pipe_run();

    public:
        virtual int run(Command*) { return 0; }
        std::vector<Redirection*> list;
        char* arguments[100];
};


#endif // __REDI_HPP__
