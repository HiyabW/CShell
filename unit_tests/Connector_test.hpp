#ifndef __CONNECTOR_TEST_HPP__
#define __CONNECTOR_TEST_HPP__

#include "gtest/gtest.h"
#include "Command.hpp"
#include "Connector.hpp"
#include "Executable.hpp"
//#include "ConnectorMock.hpp"

TEST(CommandTest, All) {
    Connector* test = new Connector();
    std::cout << "run in order:" << std::endl;
    std::cout << "ls -a" << std::endl;
    std::cout << "ls -a; mkdir no || echo && echo \"h && g\"; git status #ls # ls" << std::endl;
    std::cout << "ls -a; mkdir no || echo && echo \"h && g\"; git status" << std::endl;
    std::cout << " [empty string, just press ENTER]" << std::endl;
    std::cout << "ls -a; echo && echo \"h && g\" git status" << std::endl;
    std:: cout << "ls -a && echo hello" << std::endl;
    test->run(test);
}

#endif // __CONNECTOR_TEST_HPP__
