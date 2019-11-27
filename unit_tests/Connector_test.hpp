#ifndef __CONNECTOR_TEST_HPP__
#define __CONNECTOR_TEST_HPP__

#include "gtest/gtest.h"
#include "../header/Command.hpp"
#include "../header/Connector.hpp"
#include "../header/Executable.hpp"

TEST(CommandParseTest, LsA) {
    std::cout << "run: ls -a" << std::endl;
    Connector* test = new Connector();
    //test->run(test);
    test->parse();
    EXPECT_EQ(test->get_exec(), 1);
    EXPECT_EQ(test->get_arg(), 1);
    EXPECT_EQ(test->get_con(), 1);
}

TEST(CommandParseTest, ComboComment) {
    Connector* test = new Connector();
    std::cout << "run: ls -a; mkdir || echo && echo \"h && g\"; git status # ls" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 5);
    EXPECT_EQ(test->get_arg(), 3);
    EXPECT_EQ(test->get_con(), 5);
}

TEST(CommandParseTest, Mkdir) {
    Connector* test = new Connector();
    std::cout << "run: mkdir no; ls || echo && echo \"h && g\"; git status" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 5);
    EXPECT_EQ(test->get_arg(), 3);
    EXPECT_EQ(test->get_con(), 5);
}

TEST(CommandParseTest, Empty) {
    Connector* test = new Connector();
    std::cout << "run: [empty string, just press ENTER]" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 0);
    EXPECT_EQ(test->get_arg(), 0);
    EXPECT_EQ(test->get_con(), 0);
}

TEST(CommandParseTest, Combo) {
    Connector* test = new Connector();
    std::cout << "run: ls -a; echo && echo \"h && g\"; git status" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 4);
    EXPECT_EQ(test->get_arg(), 3);
    EXPECT_EQ(test->get_con(), 4);
}

TEST(CommandParseTest, Or) {
    Connector* test = new Connector();
    std::cout << "run: mkdir || echo hello" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 2);
    EXPECT_EQ(test->get_arg(), 1);
    EXPECT_EQ(test->get_con(), 2);
}

TEST(CommandParseTest, And) {
    Connector* test = new Connector();
    std::cout << "run: ls -a && echo hello" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 2);
    EXPECT_EQ(test->get_arg(), 2);
    EXPECT_EQ(test->get_con(), 2);
}

TEST(CommandParseTest, TestWordWithoutFlag) {
    Connector* test = new Connector();
    std::cout << "run: ls -a && test rshell" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 2);
    EXPECT_EQ(test->get_arg(), 2);
    EXPECT_EQ(test->get_con(), 2);
}

TEST(CommandParseTest, TestWordWithFlag) {
    Connector* test = new Connector();
    std::cout << "run: ls -a && test -e rshell" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 2);
    EXPECT_EQ(test->get_arg(), 3);
    EXPECT_EQ(test->get_con(), 2);
}

TEST(CommandParseTest, TestSymbolWithFlag) {
    Connector* test = new Connector();
    std::cout << "run: ls -a; [-f shell] && echo hello" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 3);
    EXPECT_EQ(test->get_arg(), 4);
    EXPECT_EQ(test->get_con(), 3);
}

TEST(CommandParseTest, TestSymbolWithoutFlag) {
    Connector* test = new Connector();
    std::cout << "run: ls -a; [shell] && echo hello" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 3);
    EXPECT_EQ(test->get_arg(), 3);
    EXPECT_EQ(test->get_con(), 3);
}

TEST(CommandParseTest, Paren) {
    Connector* test = new Connector();
    std::cout << "run: (echo hello)" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 0);
    EXPECT_EQ(test->get_arg(), 0);
    EXPECT_EQ(test->get_con(), 2);
}

TEST(CommandParseTest, ParenB) {
    Connector* test = new Connector();
    std::cout << "run: echo no; (echo hello)" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(),1);
    EXPECT_EQ(test->get_arg(), 1);
    EXPECT_EQ(test->get_con(), 3);
}

TEST(CommandParseTest, ParenA) {
    Connector* test = new Connector();
    std::cout << "run: (echo no); echo hello" << std::endl; 
    test->parse();
    EXPECT_EQ(test->get_exec(), 1);
    EXPECT_EQ(test->get_arg(), 1);
    EXPECT_EQ(test->get_con(), 3);
}

TEST(CommandParseTest, ParenBO) {
    Connector* test = new Connector();
    std::cout << "run: echo no || (echo hello)" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(),1);
    EXPECT_EQ(test->get_arg(), 1);
    EXPECT_EQ(test->get_con(), 3);
}

TEST(CommandParseTest, ParenAA) {
    Connector* test = new Connector();
    std::cout << "run: (echo no) && echo hello" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 1);
    EXPECT_EQ(test->get_arg(), 1);
    EXPECT_EQ(test->get_con(), 3);
}

TEST(CommandParseTest, ParenBA) {
    Connector* test = new Connector();
    std::cout << "run: echo no && (echo hello)" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(),1);
    EXPECT_EQ(test->get_arg(), 1);
    EXPECT_EQ(test->get_con(), 3);
}

TEST(CommandParseTest, ParenAO) {
    Connector* test = new Connector();
    std::cout << "run: (echo no) || echo hello" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 1);
    EXPECT_EQ(test->get_arg(), 1);
    EXPECT_EQ(test->get_con(), 3);
}

TEST(CommandParseTest, ParenComboA) {
    Connector* test = new Connector();
    std::cout << "run: (echo no) && (echo hello)" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 0);
    EXPECT_EQ(test->get_arg(), 0);
    EXPECT_EQ(test->get_con(), 4);
}

TEST(CommandParseTest, ParenComboO) {
    Connector* test = new Connector();
    std::cout << "run: (echo no) || (echo hello)" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 0);
    EXPECT_EQ(test->get_arg(), 0);
    EXPECT_EQ(test->get_con(), 4);
}

TEST(CommandParseTest, ParenE) {
    Connector* test = new Connector();
    std::cout << "run: (echo A && echo B; (echo no)) || (echo C && echo D)" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 0);
    EXPECT_EQ(test->get_arg(), 0);
    EXPECT_EQ(test->get_con(), 4);
}

#endif // __CONNECTOR_TEST_HPP__ 
