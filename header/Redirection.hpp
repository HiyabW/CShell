#ifndef __REDI_HPP__
#define __REDI_HPP__

#include <iostream>
#include <vector>
#include "Command.hpp"
#include "Executable.hpp"
#include "Connector.hpp"

class Redirection : public Command {
    protected:
        int input_run(int , char*[], char*[]);
        int overwrite_run(int, char*[], char*[]);
        int cat_run(int , char*[], char*[]);
        int pipe_run(int );
        //int overwrite_run_2(int );

    public:
        char* get_first(int ); 
        Redirection() : Command() {}
        virtual int run(Command*);
        char* arguments[10000];
};


#endif // __REDI_HPP__
