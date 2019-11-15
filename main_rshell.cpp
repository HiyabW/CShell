#ifndef _MAIN_R_SHELL_
#define _MAIN_R_SHELL_

#include "Command.hpp"
#include "Connector.hpp"
#include "Executable.hpp"

int main(int argc, char** argv) {
    Connector* start = new Connector;
    start->run(start);

    return 0;
}

#endif // _MAIN_R_SHELL_
