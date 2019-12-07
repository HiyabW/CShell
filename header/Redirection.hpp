#ifndef __REDI_HPP__
#define __REDI_HPP__

#include <iostream>
#include <vector>
#include "Command.hpp"

class Redirection : public Command {
    protected:
        int run();
        int input_run(int );
        int overwrite_run(int );
        int cat_run(int );
        int pipe_run(int );
        int overwrite_run_2(int );

    public:
        virtual int run(Command*) { return 0; }
        char* arguments[10000];
};


#endif // __REDI_HPP__
