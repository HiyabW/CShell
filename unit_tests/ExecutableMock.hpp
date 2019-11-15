#ifndef __EXECUTABLEMOCK_HPP__
#define __EXECUTABLEMOCK_HPP__
 
#include "../header/Executable.hpp"


class ExecutableMockOne: public Executable {
    public:
        ExecutableMockOne() { }
 
        
        /*string ls = "ls";
        string dash_l = "-l";ammer.cs.ucr.edu (Thu Nov 14 17:22:51 2019):
        
        args [0] = (char*)ls.c_str();n 5 minutes, please save your work
        args [1] = (char*) dash_l.c_str();
        args [2] = NULL;
 
        if(execvp (args[0],args) == -1 ) {
            perror("exec");   
        } 
       */
 
        //int lsRight = 1;
        //int lsWrong = -1;
        
	virtual int run(Connector*) { return 1; }
 
};


class ExecutableMockTwo: public Executable {
    public:
        ExecutableMockTwo() { }

	virtual int run(Connector*) { return 2; }

};  

class ExecutableMockZero: public Executable {
    public:
        ExecutableMockZero() { }

        virtual int run(Connector*) { return 0; }

};      

class ExecutableMockNegOne: public Executable {
    public:
        ExecutableMockNegOne() { }

        virtual int run(Connector*) { return -1; }

};       

#endif


