#ifndef __CONNECTOR_HPP__
#define __CONNECTOR_HPP__

#include "Command.hpp"
#include <vector>

class Connector {
     private: 
	   vector<Command*> myCommands;
	   int result;
	   Connector* connector; 
     public:
	Connector() {}
	
	virtual int run(Command* myExecutable1) /*should i replace with "Executable*"?*/ {
              int result = run(myCommands.at(0));
	      for(unsigned i = 1; i < myCommands.size(); ++i) {
	     
	      if(connector == ";") {
	         conditional_both(myCommands.at(i));
		 result = 1;
	      }
	      if(connector == "&&") {
		 if(result == -1) {
		   //EXECVP FAILED
		 }
		 else {
	            and_connector(myCommands.at(i));
		    result = 1;
	      	 }
	      }
	      
	      if(connector == "||") {
		 if(result == -1) {
		  //EXECVP FAILED
		 }
		 else {
	         or_connector(myCommands.at(i));
		 result = 1;
	         }
		}
	      }
	 } 
	
	void and_connector(Command* exec){
	   run(exec);
	}
	
	void or_connector(Command* exec){
	   run(exec);
	}

	virtual conditional_both(Command* exec){
	   run(exec); //run(exec) actual command
	}
};
	
#endif	
	
