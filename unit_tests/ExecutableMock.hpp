#ifndef __EXECUTABLEMOCK_HPP__
#define __EXECUTABLEMOCK_HPP__
 
#include "../header/Executable.hpp"


class ExecutableMockOne: public Executable {
    public:
        ExecutableMockOne() { }        
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

#endif // __EXECUTABLEMOCK_HPP__
