#ifndef PROMPT_CPP
#define PROMPT_CPP

#include "Prompt.hpp"
#include <cstring>
#include "Executable.hpp"

int Prompt::run(Connector* c) {
    this->parse(c);
    return 1;
}

void Prompt::parse(Connector* c) {
    /* variables */
    std::string prompt = "$ ", user_commands;
    std::string semi = ";", quote = "\"", And = "&&", Or = "||", hash = "#";
    bool exec_flag = false;
    this->execCount = 0;
    this->argCount = 0;
    this->conCount = 0;

    std::cout << prompt;
    std::getline(std::cin, user_commands);

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
            c->myCommands.push_back(newCommand);
            c->myCommands.push_back(newConnector);
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
            c->myCommands.push_back(newCommand);
            c->myCommands.push_back(newConnector);
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
            c->myCommands.push_back(newCommand);
            c->myCommands.push_back(newConnector);
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
            ++j;
        }
        else {
            arguments[j] = tokened;
            ++j;
            ++argCount;
        }
        tokened = strtok(NULL, " ");
    }
    std::cout << std::endl;
    return;
}

#endif // PROMPT_CPP
