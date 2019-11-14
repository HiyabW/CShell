#ifndef __TEST_HPP__
#define __TEST_HPP__

#include "Command.hpp"
#include "Executable.hpp"
#include "Connector.hpp"

class Test {
   TEST(ConnectorTest, andConnector) {
     /*using args is ruths idea - but why cant I just use Command* objects and pushback?*/
      Command* arg[];
      static_cast<char*>(arg[0])  = ls;
      arg[1] -> name_com = ";";
      arg[3] = ls;
      arg[4] = NULLPTR
      
      EXPECT_EQ(arg->run(arg[0]), 0);
     
     }



};
#endif
