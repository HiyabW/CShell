#ifndef __CONNECTOR_CPP__
#define __CONNECTOR_CPP__

#include "../header/Connector.hpp"
#include <stdio.h>

int Connector::run(Command* c) {
    std::string overwrite_str = ">";
    char* overwrite_c = new char[overwrite_str.size() + 1];
    strcpy(overwrite_c, overwrite_str.c_str());
    
    if(myCommands.at(0)->arguments[0] == overwrite_c) {

      std::cout << "FIRST ELEMENT OF VECTOR IS REDI" << std::endl;
    }

    while(this->myCommands.size() == 0) {
        this->parse();
    }

/* std::cout << "done parsing" << std::endl; */
/* std::cout << "ran on first in this vector, size: " << this->myCommands.size() << std::endl; */
/* std::cout << this->result << std::endl; */
    if(this->result == -2) {
/* std::cout << "called exit command" << std::endl; */
        return 0;
    }

    for(unsigned i = 2; i < this->myCommands.size(); i+=2) {
        if(this->result == -2) {
/* std::cout << "called exit command" << std::endl; */
            return 0;
        }
        connector = this->myCommands.at(i-1)->name_com;
/* std::cout << "run con: " << connector << std::endl; */
        if(connector == ";") {
/* std::cout << "in semi" << std::endl; */
            this->result = and_connector(myCommands.at(i));
        }
        else if(connector == "&&") {
/* std::cout << "in &&" << std::endl; */
            if(this->result == 1) {
                this->result = conditional_both(myCommands.at(i));
            }
        }
        else if(connector == "||") {
/* std::cout << "in ||" << std::endl; */
           if(this->result != 1) {
                this->result = or_connector(myCommands.at(i));
            }
        }
    }
    if (this->paren) {
/* std::cout << "paren result: " << this->result << std::endl; */
        return this->result;
    }

    this->myCommands.clear();
    this->run(this);

    return 0;
}

int Connector::and_connector(Command* exec) {
   int res = exec->run(exec);
/* std::cout << res << std::endl; */
   return res;
}

int Connector::or_connector(Command* exec) {
   int res = exec->run(exec);
/* std::cout << res << std::endl; */
   return res;
}

int Connector::conditional_both(Command* exec){
   int res = exec->run(exec);
/* std::cout << res << std::endl; */
   return res;
}

Redirection* Connector::RediParse(char* tokened) {
    std::cout << "PARSE RECOGNIZES ITS REDI" << std::endl;
    Redirection* r = new Redirection();
    std::string semi = ";", quote = "\"", And = "&&", Or = "||", hash = "#", o_paren = "(", c_paren = ")", o_sym = "[", c_sym = "]";
    std::string ir = "<", oro = ">", orc = ">>", pip = "|";

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

    char* os_c = new char[o_sym.size() + 1];
    strcpy(os_c, o_sym.c_str());

    char* cs_c = new char[c_sym.size() + 1];
    strcpy(cs_c, c_sym.c_str());

    char* input_c = new char[ir.size() + 1];
    strcpy(input_c, ir.c_str());

    char* overwrite_output_c = new char[oro.size() + 1];
    strcpy(overwrite_output_c, oro.c_str());

    char* cat_output_c = new char[orc.size() + 1];
    strcpy(cat_output_c, orc.c_str());

    char* pipe_c = new char[pip.size() + 1];
    strcpy(pipe_c, pip.c_str());

    int j = 0;

//std::cout<< "Error checking" << std::endl;
 
    while ( ( tokened != NULL) && (strcmp(tokened, semi_c)) && (strcmp(tokened, or_c)) && (strcmp(tokened, and_c)) ) {
        if ( (!strcmp(tokened, hash_c)) ) {
            r->arguments[j] = NULL;
            return r;
        }

        else if ( !(strcmp(tokened, quote_c)) ) {
            goto ERROR_REDI;
        }

        else if ( !(strcmp(tokened, op_c)) ) {
            goto ERROR_REDI;
        }

        else {
            r->arguments[j] = tokened;
// printf("\t\tredi arg: %s\n", r->arguments[j]); 
            ++j;
        }
        tokened = strtok(NULL, " ");
    }
    r->arguments[j] = NULL;
// printf("\t\tredi arg: %s\n", r->arguments[j]); 
    ++j;
 std::cout << "\tredi arg size: " << j << std::endl; 
    return r;

    ERROR_REDI:
    std::cout << "Error: invalid input for redirection" << std::endl;
    return nullptr;
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
// test for correct parsing
std::cout << "\texecCount: " << c->execCount << std::endl;
std::cout << "\targCount: " << c->argCount << std::endl;
std::cout << "\tconCount: " << c->conCount << std::endl;
*/
   return c;
}

void Connector::parse() {
    std::string prompt = "$ ", user_commands;
    std::string semi = ";", quote = "\"", And = "&&", Or = "||", hash = "#", o_paren = "(", c_paren = ")", o_sym = "[", c_sym = "]";
    std::string ir = "<", oro = ">", orc = ">>", pip = "|";

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

    char* os_c = new char[o_sym.size() + 1];
    strcpy(os_c, o_sym.c_str());

    char* cs_c = new char[c_sym.size() + 1];
    strcpy(cs_c, c_sym.c_str());

    char* input_c = new char[ir.size() + 1];
    strcpy(input_c, ir.c_str());

    char* overwrite_output_c = new char[oro.size() + 1];
    strcpy(overwrite_output_c, oro.c_str());

    char* cat_output_c = new char[orc.size() + 1];
    strcpy(cat_output_c, orc.c_str());

    char* pipe_c = new char[pip.size() + 1];
    strcpy(pipe_c, pip.c_str());

START:
    bool exec_flag = false, q_found = false, op_found = false, redi_found = false, is_c  = false;
    int q_count = 0, op_count = 0, cp_count = 0, j = 0;
    this->execCount = 0;
    this->argCount = 0;
    this->conCount = 0;
    this->rediCount = 0;
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
                user_commands.replace(found, 1, " ");
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

    for (unsigned i = 0; i < user_commands.size(); i++) {
        if (user_commands.at(i) == '(') {
            std::size_t pos = user_commands.find(")");
            std::string sub = user_commands.substr(i + 1, pos - 1);
            bool unpop = true;
            for (unsigned j = 0; j < sub.size(); ++j) {
                if (sub.at(j) != ' ') {
                    unpop = false;
                }
            }
            if (unpop) {
                std::cout << "Error: unpopulated '\( )\'" << std::endl;
                goto START;
            }
        }
    }

    if ( op_count != cp_count )  {
         std::cout << "Error: unpaired \'( or )\'" << std::endl;
         goto START;
     }

    for (unsigned i = 0; i < user_commands.size(); ++i) {
        if ( (user_commands.at(i) == '<') && (!redi_found)) {
            unsigned pos = 0;
            for (unsigned k = 0 ; k < i; k++) {
                if (user_commands.at(k) != ' ') {
                    is_c = true;
                }
                if ( (user_commands.at(k) == ';') || ((user_commands.at(k) == '|') && (user_commands.at(k + 1) == '|')) || (user_commands.at(k) == '&') ) {
                    pos = k + 1;
               }
               if ( (user_commands.at(k) == '(') ) {
                   pos = k + 1;
               }
            }
            if (!is_c) {
                std::cout << "Invalid input" << std::endl;
                goto START;
            }
/* std::cout << "pos:" << pos << std::endl; */
            user_commands.erase(i, 1);
/* std::cout << "erased:" << user_commands << std::endl; */
            user_commands.insert(pos, " < "); 
            i = pos + 3;
            redi_found = true;
        }
    }

    for (unsigned i = 0; i < user_commands.size(); ++i) {

        if ( (user_commands.at(i) == '>') && (user_commands.at(i+1) == '>') && (!redi_found)) {
            unsigned pos = 0;
            for (unsigned k = 0 ; k < i; k++) {
                if (user_commands.at(k) != ' ') {
                    is_c = true;
                }
                if ( (user_commands.at(k) == ';') || ((user_commands.at(k) == '|') && (user_commands.at(k + 1) == '|')) || (user_commands.at(k) == '&') ) {
                    pos = k + 1;
               }
               if ( (user_commands.at(k) == '(') ) {
                   pos = k + 1;
               }
            }
            if (!is_c) {
                std::cout << "Invalid input" << std::endl;
                goto START;
            }
/* std::cout << "pos:" << pos << std::endl; */
            user_commands.erase(i, 2);
/* std::cout << "erased:" << user_commands << std::endl; */
            user_commands.insert(pos, " >> ");
            i = pos + 4;
            redi_found = true;                                                                                                                                                              }

        else if ( (user_commands.at(i) == '>') && (user_commands.at(i+1) != '>') && (!redi_found)) {
            unsigned pos = 0;
            for (unsigned k = 0 ; k < i; k++) {
                if (user_commands.at(k) != ' ') {
                    is_c = true;
                }
                if ( (user_commands.at(k) == ';') || ((user_commands.at(k) == '|') && (user_commands.at(k + 1) == '|')) || (user_commands.at(k) == '&') ) {
                    pos = k + 1;
               }
               if ( (user_commands.at(k) == '(') ) {
                   pos = k + 1;
               }
            }
            if (!is_c) {
                std::cout << "Invalid input" << std::endl;
                goto START;
            }
/* std::cout << "pos:" << pos << std::endl; */
            user_commands.erase(i, 1);
/* std::cout << "erased:" << user_commands << std::endl; */
            user_commands.insert(pos, " > ");
            i = pos + 3;
            redi_found = true;                                                                                                                                                              }

        else {
            if (user_commands.at(i) == '>') {
                user_commands.insert(i, " ");
                if (user_commands.at(i + 2) == '>') {
                    user_commands.insert(i + 3, " ");
                    i += 3;
                }
                else {
                    user_commands.insert(i + 2, " ");
                    i += 2;
                }
            }
        }
    }

    for (unsigned i = 0; i < user_commands.size(); ++i) {

        if ( (user_commands.at(i) == '|') && (user_commands.at(i + 1) != '|') && (!redi_found)) {
            unsigned pos = 0;
            for (unsigned k = 0 ; k < i; k++) {
                if (user_commands.at(k) != ' ') {
                    is_c = true;
                }
                if ( (user_commands.at(k) == ';') || ((user_commands.at(k) == '|') && (user_commands.at(k + 1) == '|')) || (user_commands.at(k) == '&') ) {
                    pos = k + 1;
               }
               if ( (user_commands.at(k) == '(') ) {
                   pos = k + 1;
               }
            }
            if (!is_c) {
                std::cout << "Invalid input" << std::endl;
                goto START;
            }
/* std::cout << "pos:" << pos << std::endl; */
            user_commands.erase(i, 1);
/* std::cout << "erased:" << user_commands << std::endl; */
            user_commands.insert(pos, " | ");
            i = pos + 3;
            redi_found = true;
        }

        else {
            if (user_commands.at(i) == '|') {
                if ( (i != user_commands.size()) && (user_commands.at(i + 1) != '|') ) {
                    user_commands.insert(i, " ");
                    user_commands.insert(i + 2, " ");
                    i += 2;
                }
                else {
                    i += 1;
                }
            }
        }
    }

/* std::cout << user_commands << std::endl; */

    char* tokened;
    char* arguments[100];

    char* cstr = new char[user_commands.size() + 1];
    strcpy(cstr, user_commands.c_str());
    tokened = strtok(cstr, " ");

    while (tokened != NULL) {
        bool parent = false;

        if ( (!strcmp(tokened, hash_c)) ) {
            arguments[j] = NULL;
            Executable* newCommand = new Executable();
            std::copy(std::begin(arguments), std::end(arguments), std::begin(newCommand->args));
            Connector* newConnector = new Connector;
            newConnector->name_com = ";";
            newConnector->paren = false;
            this->myCommands.push_back(newCommand);
            this->myCommands.push_back(newConnector);
            j = 0;
            exec_flag = false;
            ++this->conCount;
            return;
        }

        if ( (!strcmp(tokened, input_c)) || (!strcmp(tokened, overwrite_output_c)) || (!strcmp(tokened, cat_output_c)) || (!strcmp(tokened, pipe_c))) {
            Redirection* redi = RediParse(tokened);
/* std::cout << "past redi parse" << std::endl; */
            if ( redi == nullptr ) {
/* std::cout << "redi parse returned null" << std::endl; */
                goto START;
            }
            this->myCommands.push_back(redi);
            ++this->rediCount;
            Connector* newConnector = new Connector;

            if (tokened == NULL) {
                return;
            }
            else if (!(strcmp(tokened, semi_c)))  {
                newConnector->name_com = semi;
                ++this->conCount;
            }
            else if (!(strcmp(tokened, or_c))) {
                newConnector->name_com = Or;
                ++this->conCount;
            }
            else {
                newConnector->name_com = And;
                ++this->conCount;
            }

            this->myCommands.push_back(newConnector);
            j = 0;
            //tokened = strtok(NULL, " ");
            goto NEW_START;
        }

        if ( !(strcmp(tokened, op_c)) ) {
/* printf("rParen: %s\n", tokened); */
            this->myCommands.push_back(ParenParse(tokened));
            Connector* newConnector = new Connector;
            tokened = strtok(NULL, " ");

            if (!(strcmp(tokened, semi_c)))  {
                newConnector->name_com = semi;
                ++this->conCount;
            }
            else if (!(strcmp(tokened, or_c))) {
                newConnector->name_com = Or;
                ++this->conCount;
            }
            else {
                newConnector->name_com = And;
                ++this->conCount;
            }

            this->myCommands.push_back(newConnector);
            j = 0;
            ++this->conCount;
            goto NEW_START;
        }

        if (!exec_flag) {
            exec_flag = true;
            arguments[j] = tokened;
/* printf("exe: %s\n", arguments[j]); */
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
/* printf("com: %s\n", semi_c); */
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
/* printf("com: %s\n", or_c); */
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
/* printf("com: %s\n", and_c); */
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
        NEW_START:
        tokened = strtok(NULL, " ");
     }
/*
// test for correct parsing
std::cout << "execCount: " << execCount << std::endl;
std::cout << "argCount: " << argCount << std::endl;
std::cout << "conCount: " << conCount << std::endl;
std::cout << "rediCount: " << rediCount << std::endl;
std::cout << "v size: " << this->myCommands.size() << std::endl;
*/
    this->paren = false;
    return;
}

#endif // _CONNECTOR_CPP__
