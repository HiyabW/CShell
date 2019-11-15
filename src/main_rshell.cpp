#ifndef _MAIN_R_SHELL_
#define _MAIN_R_SHELL_

#include "../header/Command.hpp"
#include "../header/Connector.hpp"
#include "../header/Executable.hpp"
#include <unistd.h>

int main(int argc, char** argv) {
    Connector* start = new Connector;
    start->run(start);

    return 0;
}

#endif // _MAIN_R_SHELL_
