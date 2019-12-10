#ifndef __UNIT_TEST_CPP__
#define __UNIT_TEST_CPP__

#include "gtest/gtest.h"
//#nclude "../unit_tests/Connector_test.hpp"
#include "../unit_tests/Connector_test.hpp" 
//#include "../unit_tests/Executable_unit_test.hpp"
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif // __UNIT_TEST_CPP__ 
