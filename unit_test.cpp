#ifndef __UNIT_TEST_CPP__
#define __UNIT_TEST_CPP__

#include "gtest/gtest.h"
#include "Connector_test.hpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif // __UNIT_TEST_CPP__
