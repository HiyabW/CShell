#ifndef _MAIN_RSHELL_
#define _MAIN_RSHELL_

#include "../header/Command.hpp"
#include "../header/Connector.hpp"
#include "../header/Executable.hpp"
#include <unistd.h>
#include <stdio.h>

int main(int argc, char** argv) {
    Connector* start = new Connector();
    start->run(start);
    /* start->parse(); */

    return 0;
}

#endif // _MAIN_RSHELL_
