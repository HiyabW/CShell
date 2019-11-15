#ifndef __CONNECTOR_MOCK_HPP__
#define __CONNECTOR_MOCK_HPP__

#include "Connector.hpp"
#include <cstring>

class ConnectorMock: public Connector {
    public:
        ConnectorMock() { }
	
	Executable* myExec;
        char* argu[3];
        std::string ls = "ls";
        std::string dash_l = "-l";
        
        argu[0] = (char*)ls.c_str();
        argu[1] = (char*) dash_l.c_str();
        argu[2] = NULL;
 
        
	Executable* myExec2;
        char* arguments2[2];
        ls = "ls";

        arguments2[0] = (char*)ls.c_str();
        //arguments2[1] = (char*) dash_l.c_str();
        arguments2[1] = NULL;
      
      /*if(execvp (args[0],args) == -1 ) {
            perror("exec");   
        } 
 	*/
	
        std::copy(std::begin(argu), std::end(argu), std::begin(myExec->args));
	std::copy(std::begin(arguments2), std::end(arguments2), std::begin(myExec2->args));
	
	int run(Command*);

};

#endif
