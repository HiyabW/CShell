#ifndef __EXECUTABLE_UNIT_TEST_HPP__
#define __EXECUTABLE_UNIT_TEST_HPP__

#include "../header/Executable.hpp"
#include "../header/Connector.hpp"

TEST(ExecutableUnitTest, ExecutableLs) {
     Connector* test = new Connector();
     std:: cout << "run: ls" << std::endl;
     test->run(test);
};

#endif
