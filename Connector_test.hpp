#ifndef __CONNECTOR_TEST_HPP__
#define __CONNECTOR_TEST_HPP__

#include "gtest/gtest.h"
#include "Command.hpp"
#include "Connector.hpp"
#include "Executable.hpp"

TEST(PromptTest, Prompt) {
    Connector* test = new Connector();
    std:: cout << "run: ls -a" << std::endl;
    test->run(test);
    EXPECT_EQ(test->get_exec(), 1);
    EXPECT_EQ(test->get_arg(), 1);
    EXPECT_EQ(test->get_con(), 1);
}

/*
TEST(PromptTest, Prompt) {
    Connector* test = new Connector();
    std:: cout << "run: ls -a; mkdir no || echo && echo \"h && g\"; git status #ls # ls" << std::endl;
    test->run(test);
    //EXPECT_EQ(test->get_exec(), 5);
    //EXPECT_EQ(test->get_arg(), 4);
    //EXPECT_EQ(test->get_con(), 4);
}

TEST(PromptTest, PromptNoComm) {
    Connector* test = new Connector();
    std:: cout << "run: ls -a; mkdir no || echo && echo \"h && g\"; git add --all" << std::endl;
    test->run(test);
    //EXPECT_EQ(test->get_exec(), 5);
    //EXPECT_EQ(test->get_arg(), 5);
    //EXPECT_EQ(test->get_con(), 5);
}

TEST(PromptTest, PromptEmpty) {
    Connector* test = new Connector();
    std:: cout << "run: " << std::endl;
    test->run(test);
    //EXPECT_EQ(test->get_exec(), 0);
    //EXPECT_EQ(test->get_arg(), 0);
    //EXPECT_EQ(test->get_con(), 0);
}

TEST(PromptTest, PromptManyArgs) {
    Connector* test = new Connector();
    std:: cout << "run: ls -a; echo && echo \"h && g\" git status" << std::endl;
    test->run(test);
    //EXPECT_EQ(test->get_exec(), 3);
    //EXPECT_EQ(test->get_arg(), 4);
    //EXPECT_EQ(test->get_con(), 3);
}
*/
#endif // __CONNECTOR_TEST_HPP__
