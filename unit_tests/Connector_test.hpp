#ifndef __CONNECTOR_TEST_HPP__
#define __CONNECTOR_TEST_HPP__

#include "gtest/gtest.h"
#include "../header/Command.hpp"
#include "../header/Connector.hpp"
#include "../header/Executable.hpp"

TEST(CommandTest, LsA) {
    Connector* test = new Connector();
    std::cout << "run: ls -a" << std::endl;
    test->run(test);
    EXPECT_EQ(test->get_exec(), 1);
    EXPECT_EQ(test->get_arg(), 1);
    EXPECT_EQ(test->get_con(), 1);
}

TEST(CommandTest, ComboComment) {
    Connector* test = new Connector();
    std::cout << "run: ls -a; mkdir || echo && echo \"h && g\"; git status # ls" << std::endl;
    test->run(test);
    EXPECT_EQ(test->get_exec(), 5);
    EXPECT_EQ(test->get_arg(), 3);
    EXPECT_EQ(test->get_con(), 5);
}

TEST(CommandTest, Mkdir) {
    Connector* test = new Connector();
    std::cout << "run: mkdir ~/assignment-yabbie_ruth/unit_tests/no; ls || echo && echo \"h && g\"; git status" << std::endl;
    test->run(test);
    EXPECT_EQ(test->get_exec(), 5);
    EXPECT_EQ(test->get_arg(), 3);
    EXPECT_EQ(test->get_con(), 5);
}

TEST(CommandTest, Empty) {
    Connector* test = new Connector();
    std::cout << "run: [empty string, just press ENTER]" << std::endl;
    test->run(test);
    EXPECT_EQ(test->get_exec(), 0);
    EXPECT_EQ(test->get_arg(), 0);
    EXPECT_EQ(test->get_con(), 0);
}

TEST(CommandTest, Combo) {
    Connector* test = new Connector();
    std::cout << "run: ls -a; echo && echo \"h && g\"; git status" << std::endl;
    test->run(test);
    EXPECT_EQ(test->get_exec(), 4);
    EXPECT_EQ(test->get_arg(), 3);
    EXPECT_EQ(test->get_con(), 4);
}

TEST(CommandTest, Or) {
    Connector* test = new Connector();
    std:: cout << "run: mkdir || echo hello" << std::endl;
    test->run(test);
    EXPECT_EQ(test->get_exec(), 2);
    EXPECT_EQ(test->get_arg(), 1);
    EXPECT_EQ(test->get_con(), 2);
}

TEST(CommandTest, AND) {
    Connector* test = new Connector();
    std:: cout << "run: ls -a && echo hello" << std::endl;
    test->run(test);
    EXPECT_EQ(test->get_exec(), 2);
    EXPECT_EQ(test->get_arg(), 2);
    EXPECT_EQ(test->get_con(), 2);
}
#endif // __CONNECTOR_TEST_HPP__
