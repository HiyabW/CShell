#ifndef __CONNECTOR_CPP__
#define __CONNECTOR_CPP__

#include "../header/Connector.hpp"
#include <stdio.h>

int Connector::run(Command* myExecutable1){
    this->parse();
    if(this->myCommands.size() == 0) {
        return 0;
    }
    if (this->myCommands.at(0)->name_com == "") {
        this->result = this->myCommands.at(0)->run(this->myCommands.at(0));
    }
    else {
        this->run(this);
    }
    for(unsigned i = 2; i < this->myCommands.size(); i+=2) {
        connector = this->myCommands.at(i-1)->name_com;
        if(connector == ";") {
            this->result = and_connector(myCommands.at(i));
        }
        else if(connector == "&&") {
            if(result == 1) {
                this->result = conditional_both(myCommands.at(i));
            }
        }
        else if(connector == "||") {
           if(result != 1) {
                this->result = or_connector(myCommands.at(i));
            }
        }
    }
    /* can be used to loop the prompt
    this->myCommands.clear();
    this->run(this);
    */
    return 0;
}

int Connector::and_connector(Command* exec) {
   return exec->run(exec);
}

int Connector::or_connector(Command* exec) {
   return exec->run(exec);
}

int Connector::conditional_both(Command* exec){
   return exec->run(exec);
}

void Connector::parse() {
   std::string prompt = "$ ", user_commands;
   std::string semi = ";", quote = "\"", And = "&&", Or = "||", hash = "#";

   char* semi_c = new char[semi.size() + 1];
   strcpy(semi_c, semi.c_str());
   char* quote_c = new char[quote.size() + 1];
   strcpy(quote_c, quote.c_str());
   char* and_c = new char[And.size() + 1];
   strcpy(and_c, And.c_str());
   char* or_c = new char[Or.size() + 1];
   strcpy(or_c, Or.c_str());
   char* hash_c = new char[hash.size() + 1];
   strcpy(hash_c, hash.c_str());

START:
   bool exec_flag = false, q_found = false;
   int q_count = 0, j = 0;
   this->execCount = 0;
   this->argCount = 0;
   this->conCount = 0;
   std::cout << prompt;
   std::getline(std::cin, user_commands);
   std::cout << std::endl;

/* std::cout << user_commands << std::endl; */

   if (user_commands.empty() || (user_commands.at(0) == '#')) {
       return;
   }

   user_commands.append(semi);

   for (unsigned i = 0; i < user_commands.size(); ++i) {
       if (user_commands.at(i) == ';') {
           user_commands.insert(i, " ");
           ++i;
       }
   }

   for (unsigned i = 0; i < user_commands.size(); ++i) {
       if (user_commands.at(i) == '[') {
           user_commands.replace(i, 1, "test ");
           std::size_t found = user_commands.find(']');
           if (found == std::string::npos) {
               std::cout << "Error: unpaired \'[\'" << std::endl;
               goto START;
           }
           else {
               user_commands.replace(i, 1, " ");
           }
       }
   }

   for (unsigned i = 0; i < user_commands.size(); ++i) {
       if (user_commands.at(i) == '\"') {
           user_commands.insert(i, " ");
           ++i;
           ++q_count;
           q_found = true;
           user_commands.insert( (i + 1), " ");
       }
   }

   if (q_found && ((q_count % 2) != 0) ) {
       std::cout << "Error: unpaired \'\"\'" << std::endl;
       goto START;
   }

   for (unsigned i = 0; i < user_commands.size(); ++i) {
       if (user_commands.at(i) == '#') {
           user_commands.insert(i, " ");
           ++i;
           user_commands.insert( (i + 1), " ");
       }
   }

/* std::cout << user_commands << std::endl; */

   char* tokened;
   char* arguments[100];

   char* cstr = new char[user_commands.size() + 1];
   strcpy(cstr, user_commands.c_str());
   tokened = strtok(cstr, " ");

   while (tokened != NULL) {
       if ( (!strcmp(tokened, hash_c)) ) {
           arguments[j] = NULL;
           Executable* newCommand = new Executable();
           std::copy(std::begin(arguments), std::end(arguments), std::begin(newCommand->args));
           Connector* newConnector = new Connector;
           newConnector->name_com = ";";
           this->myCommands.push_back(newCommand);
           this->myCommands.push_back(newConnector);
           j = 0;
           exec_flag = false;
           ++conCount;
           return;
       }
       else if (!exec_flag) {
           exec_flag = true;
           arguments[j] = tokened;
/* printf("exec: %s\n", arguments[j]); */
           ++execCount;
           ++j;
       }
       else if ( !(strcmp(tokened, semi_c)) ) {
           arguments[j] = NULL;
           Executable* newCommand = new Executable();
           std::copy(std::begin(arguments), std::end(arguments), std::begin(newCommand->args));
           Connector* newConnector = new Connector;
           newConnector->name_com = semi;
           this->myCommands.push_back(newCommand);
           this->myCommands.push_back(newConnector);
           j = 0;
           exec_flag = false;
           ++conCount;
       }
       else if ( !(strcmp(tokened, or_c)) ) {
           arguments[j] = NULL;
           Executable* newCommand = new Executable();
           std::copy(std::begin(arguments), std::end(arguments), std::begin(newCommand->args));
           Connector* newConnector = new Connector;
           newConnector->name_com = Or;
           this->myCommands.push_back(newCommand);
           this->myCommands.push_back(newConnector);
           j = 0;
           exec_flag = false;
           ++conCount;
       }
       else if ( !(strcmp(tokened, and_c)) ) {
           arguments[j] = NULL;
           Executable* newCommand = new Executable();
           std::copy(std::begin(arguments), std::end(arguments), std::begin(newCommand->args));
           Connector* newConnector = new Connector;
           newConnector->name_com = And;
           this->myCommands.push_back(newCommand);
           this->myCommands.push_back(newConnector);
           j = 0;
           exec_flag = false;
           ++conCount;
       }
       else if ( !(strcmp(tokened, quote_c)) ) {
           std::string quoteToken;
           ++argCount;
           tokened = strtok(NULL, " ");
           while ( (tokened != NULL) && (strcmp(tokened, quote_c)) ) {
               std::string temp(tokened);
               quoteToken.append(temp);
               quoteToken.append(" ");
               tokened = strtok(NULL, " ");
           }
           char* token = new char[quoteToken.size() + 1];
           strcpy(token, quoteToken.c_str());
           arguments[j] = token;
/* printf("arg: %s\n", arguments[j]); */
           ++j;
       }
       else {
            arguments[j] = tokened;
/* printf("arg: %s\n", arguments[j]); */
           ++j;
           ++argCount;
       }
       tokened = strtok(NULL, " ");
   }

/* // test for correct parsing
std::cout << "execCount: " << execCount << std::endl;
std::cout << "argCount: " << argCount << std::endl;
std::cout << "conCount: " << conCount << std::endl;
*/

   return;
}

#endif // _CONNECTOR_CPP__
