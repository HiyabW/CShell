#ifndef __CONNECTOR_CPP__
#define __CONNECTOR_CPP__

#include "Connector.hpp"
      
int Connector::run(Command* myExecutable1){
        this->parse();
        if (myCommands.at(0)->name_com == "") {
            this->result = myCommands.at(0)->run(myCommands.at(0));
            //std::cout << "start" << result << std::endl;
        }
        else {
            this->run(this);
        }
        for(unsigned i = 2; i < myCommands.size(); i+=2) {
            connector = myCommands.at(i-1)->name_com;
            if(connector == ";") {
                this->result = and_connector(myCommands.at(i));
                //std::cout << ";" << result << std::endl;
            }
            else if(connector == "&&") {
                if(result == 1) {
                    this->result = conditional_both(myCommands.at(i));
                    //std::cout << "&&" << result << std::endl;
                }
            }
            else if(connector == "||") {
                if(result != 1) {
                    this->result = or_connector(myCommands.at(i));
                }
            }
        }
        this->myCommands.clear();
    this->run(this);
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
    /* variables */
    std::string prompt = "$ ", user_commands;
    std::string semi = ";", quote = "\"", And = "&&", Or = "||", hash = "#";
    bool exec_flag = false;
    this->execCount = 0;
    this->argCount = 0;
    this->conCount = 0;

    std::cout << prompt;
    std::getline(std::cin, user_commands);

    if (user_commands.empty()) {
        return;
    }

    /* insert terminating ; */
    user_commands.append(semi);

    /* insert spaces before ; in user_commands */
    for (unsigned i = 0; i < user_commands.size(); ++i) {
        if (user_commands.at(i) == ';') {
            user_commands.insert(i, " ");
            ++i;
        }
    }

    /* insert spaces before and after " in user_commands */
    for (unsigned i = 0; i < user_commands.size(); ++i) {
        if (user_commands.at(i) == '\"') {
            user_commands.insert(i, " ");
            ++i;
            user_commands.insert( (i + 1), " ");
        }
    }

    /* insert spaces before and after # in user_commands */
    for (unsigned i = 0; i < user_commands.size(); ++i) {
        if (user_commands.at(i) == '#') {
            user_commands.insert(i, " ");
            ++i;
            user_commands.insert( (i + 1), " ");
        }
    }

    /* cstring */
    char* cstr = new char[user_commands.size() + 1];
    strcpy(cstr, user_commands.c_str());
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

    char* tokened;
    char* arguments[100];
    int j = 0;

    tokened = strtok(cstr, " ");
    while (tokened != NULL) {
        if ( (!strcmp(tokened, hash_c)) ) {
            return;
        }
        else if (!exec_flag) {
            exec_flag = true;
            arguments[j] = tokened;
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
            //printf("arg: %s\n", token);
            ++j;
        }
        else {
            arguments[j] = tokened;
            ++j;
            ++argCount;
        }
        tokened = strtok(NULL, " ");
    }
    //std::cout << "\tnum exe: " << this->execCount << std::endl;
    //std::cout << "\tnum exe: " << this->execCount << std::endl;
    //std::cout << "\tnum exe: " << this->execCount << std::endl;
    //std::cout << "\tvector size: " << this->myCommands.size() << std::endl;
    return;
}

#endif 

