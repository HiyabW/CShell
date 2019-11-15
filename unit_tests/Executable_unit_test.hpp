#ifndef __EXECUTABLE_UNIT_TEST_HPP__
#define __EXECUTABLE_UNIT_TEST_HPP__

#include "Executable.hpp"
#include "Connector.hpp"

TEST(ExecutableUnitTest, ExecutableLs) {
     Connector* test = new Connector();
     std:: cout << "run: ls" << std::endl;
     test->run(test);
};

#endif
