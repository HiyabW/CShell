#ifndef __CONNECTOR_TEST2_HPP__
#define __CONNECTOR_TEST2_HPP__

#include "Connector.hpp"

TEST(ConnectorTest3, ConnectorConditionalBoth) {
    Connector* test = new Connector();
    std:: cout << "run: ls -a || echo hello" << std::endl;
    test->run(test);
        EXPECT_EQ(test->run(test), 0);
}
#endif
