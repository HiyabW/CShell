#ifndef __CONNECTOR_TEST_HPP__
#define __CONNECTOR_TEST_HPP__

#include "gtest/gtest.h"
#include "../header/Command.hpp"
#include "../header/Connector.hpp"
#include "../header/Executable.hpp"

TEST(CommandTest, LsA) {
    std::cout << "run: ls -a" << std::endl;
    Connector* test = new Connector();
    //test->run(test);
    test->parse();
    EXPECT_EQ(test->get_exec(), 1);
    EXPECT_EQ(test->get_arg(), 1);
    EXPECT_EQ(test->get_con(), 1);
}

TEST(CommandTest, ComboComment) {
    Connector* test = new Connector();
    std::cout << "run: ls -a; mkdir || echo && echo \"h && g\"; git status # ls" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 5);
    EXPECT_EQ(test->get_arg(), 3);
    EXPECT_EQ(test->get_con(), 5);
}

TEST(CommandTest, Mkdir) {
    Connector* test = new Connector();
    std::cout << "run: mkdir no; ls || echo && echo \"h && g\"; git status" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 5);
    EXPECT_EQ(test->get_arg(), 3);
    EXPECT_EQ(test->get_con(), 5);
}

TEST(CommandTest, Empty) {
    Connector* test = new Connector();
    std::cout << "run: [empty string, just press ENTER]" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 0);
    EXPECT_EQ(test->get_arg(), 0);
    EXPECT_EQ(test->get_con(), 0);
}

TEST(CommandTest, Combo) {
    Connector* test = new Connector();
    std::cout << "run: ls -a; echo && echo \"h && g\"; git status" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 4);
    EXPECT_EQ(test->get_arg(), 3);
    EXPECT_EQ(test->get_con(), 4);
}

TEST(CommandTest, Or) {
    Connector* test = new Connector();
    std:: cout << "run: mkdir || echo hello" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 2);
    EXPECT_EQ(test->get_arg(), 1);
    EXPECT_EQ(test->get_con(), 2);
}

TEST(CommandTest, And) {
    Connector* test = new Connector();
    std:: cout << "run: ls -a && echo hello" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 2);
    EXPECT_EQ(test->get_arg(), 2);
    EXPECT_EQ(test->get_con(), 2);
}

TEST(CommandTest, TestWordWithoutFlag) {
    Connector* test = new Connector();
    std:: cout << "run: ls -a && test rshell" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 2);
    EXPECT_EQ(test->get_arg(), 2);
    EXPECT_EQ(test->get_con(), 2);
}

TEST(CommandTest, TestWordWithFlag) {
    Connector* test = new Connector();
    std:: cout << "run: ls -a && test -e rshell" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 2);
    EXPECT_EQ(test->get_arg(), 3);
    EXPECT_EQ(test->get_con(), 2);
}

TEST(CommandTest, TestSymbolWithFlag) {
    Connector* test = new Connector();
    std:: cout << "run: ls -a; [-f shell] && echo hello" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 3);
    EXPECT_EQ(test->get_arg(), 4);
    EXPECT_EQ(test->get_con(), 3);
}

TEST(CommandTest, TestSymbolWithoutFlag) {
    Connector* test = new Connector();
    std:: cout << "run: ls -a; [shell] && echo hello" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 3);
    EXPECT_EQ(test->get_arg(), 3);
    EXPECT_EQ(test->get_con(), 3);
}

TEST(CommandTest, Paren) {
    Connector* test = new Connector();
    std:: cout << "run: (echo hello)" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 0);
    EXPECT_EQ(test->get_arg(), 0);
    EXPECT_EQ(test->get_con(), 2);
}

TEST(CommandTest, ParenB) {
    Connector* test = new Connector();
    std:: cout << "run: echo no; (echo hello)" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(),1);
    EXPECT_EQ(test->get_arg(), 1);
    EXPECT_EQ(test->get_con(), 3);
}

TEST(CommandTest, ParenA) {                                                                                                                                                             Connector* test = new Connector();
    std:: cout << "run: (echo no); echo hello" << std::endl; 
    test->parse();
    EXPECT_EQ(test->get_exec(), 1);
    EXPECT_EQ(test->get_arg(), 1);
    EXPECT_EQ(test->get_con(), 3);
}

TEST(CommandTest, ParenBO) {
    Connector* test = new Connector();
    std:: cout << "run: echo no || (echo hello)" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(),1);
    EXPECT_EQ(test->get_arg(), 1);
    EXPECT_EQ(test->get_con(), 3);
}

TEST(CommandTest, ParenAA) {
    Connector* test = new Connector();
    std:: cout << "run: (echo no) && echo hello" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 1);
    EXPECT_EQ(test->get_arg(), 1);
    EXPECT_EQ(test->get_con(), 3);
}

TEST(CommandTest, ParenBA) {
    Connector* test = new Connector();
    std:: cout << "run: echo no && (echo hello)" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(),1);
    EXPECT_EQ(test->get_arg(), 1);
    EXPECT_EQ(test->get_con(), 3);
}

TEST(CommandTest, ParenAO) {
    Connector* test = new Connector();
    std:: cout << "run: (echo no) || echo hello" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 1);
    EXPECT_EQ(test->get_arg(), 1);
    EXPECT_EQ(test->get_con(), 3);
}

TEST(CommandTest, ParenComboA) {
    Connector* test = new Connector();
    std:: cout << "run: (echo no) && (echo hello)" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 0);
    EXPECT_EQ(test->get_arg(), 0);
    EXPECT_EQ(test->get_con(), 4);
}

TEST(CommandTest, ParenComboO) {
    Connector* test = new Connector();
    std:: cout << "run: (echo no) || (echo hello)" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 0);
    EXPECT_EQ(test->get_arg(), 0);
    EXPECT_EQ(test->get_con(), 4);
}

TEST(CommandTest, ParenE) {
    Connector* test = new Connector();
    std:: cout << "run: (echo A && echo B; (echo no)) || (echo C && echo D)" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 0);
    EXPECT_EQ(test->get_arg(), 0);
    EXPECT_EQ(test->get_con(), 4);
}

#endif // __CONNECTOR_TEST_HPP__ 
