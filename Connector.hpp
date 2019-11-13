#ifndef __CONNECTOR_HPP__
#define __CONNECTOR_HPP__

#include "Command.hpp"

class Connector {
     private: 
	   vector<Command*> myCommands;
	   Executable* myExecutable1;
	   Executable* myExecutable2;
	   string connector; 
     public:
	Connector() {}
	
	virtual int run(Command* myExecutable1) /*should i replace with "Executable*"?*/ {
           for(unsigned i = 0; i < myCommands.size(); i+=2) {
	      myCommands->at(i) = myExecutable1;
	      myCommands->at(i+1)->name_com = connector;
	      myCommands->at(i+2)-> = myExecutable2;

	     
	      int result1 = run(myExecutable1);
	      if(connector == ";") {
	         conditional_both(myExecutable2);
	      }
	      if(connector == "&&" && result1 = 1) {
	         and_connector(myExecutable2);
	      }
	      if(connector == "||" && result1 = 0) {
	         or_connector(myExecutable2);
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
	   run(exec);
	}
};
	
#endif	
	
