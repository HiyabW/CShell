#ifndef __UNIT_TEST_CPP__
#define __UNIT_TEST_CPP__

#include "gtest/gtest.h"
//INTEGRATION TEST:::::: #include "Connector_test.hpp"
//#include "Connector_test3.hpp"
//#include "Connector_test4.hpp"
//#include "../unit_tests/ConnectorMock.hpp"
#include "../unit_tests/ExecutableMock.hpp"
#include "../unit_tests/Executable_unit_test.hpp"
#include "../unit_tests/Connector_test.hpp" 
//
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif // __UNIT_TEST_CPP__
