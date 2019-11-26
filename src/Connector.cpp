#ifndef __CONNECTOR_CPP__
#define __CONNECTOR_CPP__

#include "../header/Connector.hpp"
#include <stdio.h>

int Connector::run(Command* c) {
/*
    std::cout << "outer, vector size: " << this->myCommands.size() << std::endl;
    if (this->paren) {
        std::cout << "in paren, vector size: " << this->myCommands.size() << std::endl;
    }
*/
    while(this->myCommands.size() == 0) {
        this->parse();
    }

//std::cout << "outer result: " << this->result << std::endl;
    while(this->myCommands.size() == 0) {
        this->parse();
    }
//std::cout << "done parsing" << std::endl;
/*
if (this->paren) {
    goto PAREN_LP;}
}
*/
//    if (this->myCommands.at(0)->name_com == "") {
        this->result = this->myCommands.at(0)->run(this->myCommands.at(0));
//std::cout << "ran on first in this vector, size: " << this->myCommands.size() << std::endl;
/* std::cout << this->result << std::endl; */
        if(this->result == -2) {
/* std::cout << "called exit command" << std::endl; */
            return 0;
        }
/*
        if(this->myCommands.size() < 3 && this->myCommands.size() > 1) {
           if(this->myCommands.at(1)->name_com != ";" || this->myCommands.at(1)->name_com != "||" || this->myCommands.at(1)->name_com != "&&") {
                if (this->result == 0) {
                    return 1;
                }
            }
        } 
*/          
//    }
//    else {
//        this->myCommands.clear();
//        this->run(this);
//    }
//PAREN_LP:
    for(unsigned i = 2; i < this->myCommands.size(); i+=2) {
        if(this->result == -2) {
//std::cout << "called exit command" << std::endl; 
            return 0;
        }
        connector = this->myCommands.at(i-1)->name_com;
//std::cout << "run con: " << connector << std::endl;
        if(connector == ";") {
//std::cout << "in semi" << std::endl;
            this->result = and_connector(myCommands.at(i));
        }
        else if(connector == "&&") {
//std::cout << "in &&" << std::endl;
            if(this->result == 1) {
                this->result = conditional_both(myCommands.at(i));
            }
        }
        else if(connector == "||") {
//std::cout << "in ||" << std::endl;
           if(this->result != 1) {
                this->result = or_connector(myCommands.at(i));
            }
        }
    }
    if (this->paren) {
//std::cout << "paren result: " << this->result << std::endl;
        return this->result;
    }

/*
    this->myCommands.clear();
    this->run(this);

    if (!this->paren) {
        this->myCommands.clear();
        this->run(this);
    return 0;

    if (!this->paren) {
std::cout << "non paren looper" << std::endl;
         this->myCommands.clear();
         this->run(this);
         return 0;
    }
    return this->result;
*/

    this->myCommands.clear();
    this->run(this);

    return 0;

}

int Connector::and_connector(Command* exec) {
   int res = exec->run(exec);
//   std::cout << res << std::endl;
   return res;
}

int Connector::or_connector(Command* exec) {
   int res = exec->run(exec);
//   std::cout << res << std::endl;
   return res;
}

int Connector::conditional_both(Command* exec){
   int res = exec->run(exec);
//   std::cout << res << std::endl;
   return res;
}

Connector* Connector::ParenParse(char* tokened) {
   Connector* c = new Connector();
   std::string semi = ";", quote = "\"", And = "&&", Or = "||", hash = "#", o_paren = "(", c_paren = ")";

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
   char* op_c = new char[o_paren.size() + 1];
   strcpy(op_c, o_paren.c_str());
   char* cp_c = new char[c_paren.size() + 1];
   strcpy(cp_c, c_paren.c_str());

   bool exec_flag = false, q_found = false, op_found = false;
   int q_count = 0, op_count = 0, cp_count = 0, j = 0;
   c->execCount = 0;
   c->argCount = 0;
   c->conCount = 0;

   char* arguments[100];
/* printf("\ttoken1: %s\n", tokened); */
   tokened = strtok(NULL, " ");
   while ( (strcmp(tokened, cp_c)) ) {
/* printf("\ttoken2: %s\n", tokened); */
       if ( (!strcmp(tokened, hash_c)) ) {
           arguments[j] = NULL;
           Executable* newCommand = new Executable();
           std::copy(std::begin(arguments), std::end(arguments), std::begin(newCommand->args));
           Connector* newConnector = new Connector;
           newConnector->name_com = ";";
           c->myCommands.push_back(newCommand);
           c->myCommands.push_back(newConnector);
           j = 0;
           exec_flag = false;
           ++c->conCount;
           return c;
       }

if ( !(strcmp(tokened, op_c)) ) {
/* printf("\trParen: %s\n", tokened); */
    c->myCommands.push_back(ParenParse(tokened));
/* printf("\toutParen: %s\n", tokened); */
}

       if (!exec_flag) {
           exec_flag = true;
           arguments[j] = tokened;
/* printf("\texec: %s\n", arguments[j]); */
           ++c->execCount;
           ++j;
       }

       else if ( !(strcmp(tokened, semi_c)) ) {
           arguments[j] = NULL;
           Executable* newCommand = new Executable();
           std::copy(std::begin(arguments), std::end(arguments), std::begin(newCommand->args));
           Connector* newConnector = new Connector;
           newConnector->name_com = semi;
           c->myCommands.push_back(newCommand);
           c->myCommands.push_back(newConnector);
           j = 0;
           exec_flag = false;
           ++c->conCount;
       }

       else if ( !(strcmp(tokened, or_c)) ) {
           arguments[j] = NULL;
           Executable* newCommand = new Executable();
           std::copy(std::begin(arguments), std::end(arguments), std::begin(newCommand->args));
           Connector* newConnector = new Connector;
           newConnector->name_com = Or;
           c->myCommands.push_back(newCommand);
           c->myCommands.push_back(newConnector);
           j = 0;
           exec_flag = false;
           ++c->conCount;
       }

       else if ( !(strcmp(tokened, and_c)) ) {
           arguments[j] = NULL;
           Executable* newCommand = new Executable();
           std::copy(std::begin(arguments), std::end(arguments), std::begin(newCommand->args));
           Connector* newConnector = new Connector;
           newConnector->name_com = And;
           c->myCommands.push_back(newCommand);
           c->myCommands.push_back(newConnector);
           j = 0;
           exec_flag = false;
           ++c->conCount;
       }

       else if ( !(strcmp(tokened, quote_c)) ) {
           std::string quoteToken;
           ++c->argCount;
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
/* printf("\targ: %s\n", arguments[j]); */
           ++j;
       }

       else {
            arguments[j] = tokened;
/* printf("\targ: %s\n", arguments[j]); */
           ++j;
           ++c->argCount;
       }
       tokened = strtok(NULL, " ");
   }

    arguments[j] = NULL;
    Executable* newCommand = new Executable();
    std::copy(std::begin(arguments), std::end(arguments), std::begin(newCommand->args));
    Connector* newConnector = new Connector;
    newConnector->name_com = semi;
    c->myCommands.push_back(newCommand);
    c->myCommands.push_back(newConnector);
    c->paren = true;

/*
printf("\tending token:%s\n", tokened);
// test for correct parsing
std::cout << "\texecCount: " << c->execCount << std::endl;
std::cout << "\targCount: " << c->argCount << std::endl;
std::cout << "\tconCount: " << c->conCount << std::endl;
*/
   return c;
}

void Connector::parse() {
   std::string prompt = "$ ", user_commands;
   std::string semi = ";", quote = "\"", And = "&&", Or = "||", hash = "#", o_paren = "(", c_paren = ")";

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

   char* op_c = new char[o_paren.size() + 1];
   strcpy(op_c, o_paren.c_str());
   char* cp_c = new char[c_paren.size() + 1];
   strcpy(cp_c, c_paren.c_str());

START:
   bool exec_flag = false, q_found = false, op_found = false;
   int q_count = 0, op_count = 0, cp_count = 0, j = 0;
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

   if (user_commands.at(user_commands.size() - 1) != ';') {
       user_commands.append(semi);
   }

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

   for (unsigned i = 0; i < user_commands.size(); ++i) {
       if (user_commands.at(i) == '(') {
           user_commands.insert(i + 1, " ");
           op_found = true;
           ++op_count;
           ++i;
       }
   }

   for (unsigned i = 0; i < user_commands.size(); ++i) {
       if (user_commands.at(i) == ')') {
           user_commands.insert(i, " ");
           user_commands.insert(i + 2, " ");
           ++cp_count;
           i += 2;
       }
   }

   if ( op_count != cp_count )  {
        std::cout << "Error: unpaired \'( or )\'" << std::endl;
        goto START;
    }
 
/* std::cout << user_commands << std::endl; */

   char* tokened;
   char* arguments[100];

   char* cstr = new char[user_commands.size() + 1];
   strcpy(cstr, user_commands.c_str());
   tokened = strtok(cstr, " ");

   while (tokened != NULL) {
NEW_START:
       bool parent = false;
       if ( (!strcmp(tokened, hash_c)) ) {
           arguments[j] = NULL;
           Executable* newCommand = new Executable();
           std::copy(std::begin(arguments), std::end(arguments), std::begin(newCommand->args));
           Connector* newConnector = new Connector;
           newConnector->name_com = ";";
           newConnector->paren = false;
           this->myCommands.push_back(newCommand);
//std::cout << "pb" << std::endl;
           this->myCommands.push_back(newConnector);
//std::cout << "pb" << std::endl;
           j = 0;
           exec_flag = false;
           ++this->conCount;
           return;
       }

   if ( !(strcmp(tokened, op_c)) ) {
/* printf("rParen: %s\n", tokened); */
      // paren = true;
       this->myCommands.push_back(ParenParse(tokened));
       ++this->conCount;
       exec_flag = true;
       Connector* newConnector = new Connector;
       tokened = strtok(NULL, " ");

       if (!(strcmp(tokened, semi_c)))  {
           newConnector->name_com = semi;
       }
       else if (!(strcmp(tokened, or_c))) {
           newConnector->name_com = Or;
       }
       else {
           newConnector->name_com = And;
       }

       this->myCommands.push_back(newConnector);
       j = 0;
       exec_flag = false;
       ++this->conCount;
       //tokened = strtok(NULL, " ");
//printf("outParen: %s\n", tokened);
//goto NEW_START;
       tokened = strtok(NULL, " ");
/* printf("outParen: %s\n", tokened); */
   }

       if (!exec_flag) {
           exec_flag = true;
           arguments[j] = tokened;
/* printf("exec: %s\n", arguments[j]); */
           ++this->execCount;
           ++j;
       }

       else if ( !(strcmp(tokened, semi_c)) ) {
           if (!paren) {
               arguments[j] = NULL;
               Executable* newCommand = new Executable();
               std::copy(std::begin(arguments), std::end(arguments), std::begin(newCommand->args));
               this->myCommands.push_back(newCommand);
           }
               Connector* newConnector = new Connector;
               newConnector->name_com = semi;
               newConnector->paren = false;
           this->myCommands.push_back(newConnector);
           j = 0;
           exec_flag = false;
           ++this->conCount;
       }

       else if ( !(strcmp(tokened, or_c)) ) {
           if (!paren) {
               arguments[j] = NULL;
               Executable* newCommand = new Executable();
               std::copy(std::begin(arguments), std::end(arguments), std::begin(newCommand->args));
               this->myCommands.push_back(newCommand);
           }
           Connector* newConnector = new Connector;
           newConnector->name_com = Or;
           newConnector->paren = false;
           this->myCommands.push_back(newConnector);
           j = 0;
           exec_flag = false;
           ++this->conCount;
       }

       else if ( !(strcmp(tokened, and_c)) ) {
           if (!paren) {
               arguments[j] = NULL;
               Executable* newCommand = new Executable();
               std::copy(std::begin(arguments), std::end(arguments), std::begin(newCommand->args));
               this->myCommands.push_back(newCommand);
           }
           Connector* newConnector = new Connector;
           newConnector->name_com = And;
           newConnector->paren = false;
           this->myCommands.push_back(newConnector);
           j = 0;
           exec_flag = false;
           ++this->conCount;
       }

       else if ( !(strcmp(tokened, quote_c)) ) {
           std::string quoteToken;
           ++this->argCount;
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
           ++this->argCount;
       }
       tokened = strtok(NULL, " ");
/* printf("token: %s\n", tokened); */
    }
/*
// test for correct parsing
std::cout << "execCount: " << execCount << std::endl;
std::cout << "argCount: " << argCount << std::endl;
std::cout << "conCount: " << conCount << std::endl;
std::cout << "v size: " << this->myCommands.size() << std::endl;
*/
this->paren = false;
   return;
}

#endif // _CONNECTOR_CPP__
