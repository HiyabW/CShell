#ifndef __CONNECTOR_TEST_HPP__
#define __CONNECTOR_TEST_HPP__

#include "gtest/gtest.h"
#include "../header/Command.hpp"
#include "../header/Connector.hpp"
#include "../header/Executable.hpp"
/*
TEST(CommandParseTest, LsA) {
    std::cout << "run: ls -a" << std::endl;
    Connector* test = new Connector();
    test->parse();
    EXPECT_EQ(test->get_exec(), 1);
    EXPECT_EQ(test->get_arg(), 1);
    EXPECT_EQ(test->get_con(), 1);
    EXPECT_EQ(test->get_redi(), 0);
}

TEST(CommandParseTest, ComboComment) {
    Connector* test = new Connector();
    std::cout << "run: ls -a; mkdir || echo && echo \"h && g\"; git status # ls" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 5);
    EXPECT_EQ(test->get_arg(), 3);
    EXPECT_EQ(test->get_con(), 5);
    EXPECT_EQ(test->get_redi(), 0);
}

TEST(CommandParseTest, Mkdir) {
    Connector* test = new Connector();
    std::cout << "run: mkdir no; ls || echo && echo \"h && g\"; git status" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 5);
    EXPECT_EQ(test->get_arg(), 3);
    EXPECT_EQ(test->get_con(), 5);
    EXPECT_EQ(test->get_redi(), 0);
}

TEST(CommandParseTest, Empty) {
    Connector* test = new Connector();
    std::cout << "run: [empty string, just press ENTER]" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 0);
    EXPECT_EQ(test->get_arg(), 0);
    EXPECT_EQ(test->get_con(), 0);
    EXPECT_EQ(test->get_redi(), 0);
}

TEST(CommandParseTest, Combo) {
    Connector* test = new Connector();
    std::cout << "run: ls -a; echo && echo \"h && g\"; git status" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 4);
    EXPECT_EQ(test->get_arg(), 3);
    EXPECT_EQ(test->get_con(), 4);
    EXPECT_EQ(test->get_redi(), 0);
}

TEST(CommandParseTest, Or) {
    Connector* test = new Connector();
    std::cout << "run: mkdir || echo hello" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 2);
    EXPECT_EQ(test->get_arg(), 1);
    EXPECT_EQ(test->get_con(), 2);
    EXPECT_EQ(test->get_redi(), 0);
}

TEST(CommandParseTest, And) {
    Connector* test = new Connector();
    std::cout << "run: ls -a && echo hello" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 2);
    EXPECT_EQ(test->get_arg(), 2);
    EXPECT_EQ(test->get_con(), 2);
    EXPECT_EQ(test->get_redi(), 0);
}

TEST(CommandParseTest, TestWordWithoutFlag) {
    Connector* test = new Connector();
    std::cout << "run: ls -a && test rshell" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 2);
    EXPECT_EQ(test->get_arg(), 2);
    EXPECT_EQ(test->get_con(), 2);
    EXPECT_EQ(test->get_redi(), 0);
}

TEST(CommandParseTest, TestWordWithFlag) {
    Connector* test = new Connector();
    std::cout << "run: ls -a && test -e rshell" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 2);
    EXPECT_EQ(test->get_arg(), 3);
    EXPECT_EQ(test->get_con(), 2);
    EXPECT_EQ(test->get_redi(), 0);
}

TEST(CommandParseTest, TestSymbolWithFlag) {
    Connector* test = new Connector();
    std::cout << "run: ls -a; [-f shell] && echo hello" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 3);
    EXPECT_EQ(test->get_arg(), 4);
    EXPECT_EQ(test->get_con(), 3);
    EXPECT_EQ(test->get_redi(), 0);
}

TEST(CommandParseTest, TestSymbolWithoutFlag) {
    Connector* test = new Connector();
    std::cout << "run: ls -a; [shell] && echo hello" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 3);
    EXPECT_EQ(test->get_arg(), 3);
    EXPECT_EQ(test->get_con(), 3);
    EXPECT_EQ(test->get_redi(), 0);
}

TEST(CommandParseTest, Paren) {
    Connector* test = new Connector();
    std::cout << "run: (echo hello)" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 0);
    EXPECT_EQ(test->get_arg(), 0);
    EXPECT_EQ(test->get_con(), 2);
    EXPECT_EQ(test->get_redi(), 0);
}

TEST(CommandParseTest, ParenB) {
    Connector* test = new Connector();
    std::cout << "run: echo no; (echo hello)" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(),1);
    EXPECT_EQ(test->get_arg(), 1);
    EXPECT_EQ(test->get_con(), 3);
    EXPECT_EQ(test->get_redi(), 0);
}

TEST(CommandParseTest, ParenA) {
    Connector* test = new Connector();
    std::cout << "run: (echo no); echo hello" << std::endl; 
    test->parse();
    EXPECT_EQ(test->get_exec(), 1);
    EXPECT_EQ(test->get_arg(), 1);
    EXPECT_EQ(test->get_con(), 3);
    EXPECT_EQ(test->get_redi(), 0);
}

TEST(CommandParseTest, ParenBO) {
    Connector* test = new Connector();
    std::cout << "run: echo no || (echo hello)" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(),1);
    EXPECT_EQ(test->get_arg(), 1);
    EXPECT_EQ(test->get_con(), 3);
    EXPECT_EQ(test->get_redi(), 0);
}

TEST(CommandParseTest, ParenAA) {
    Connector* test = new Connector();
    std::cout << "run: (echo no) && echo hello" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 1);
    EXPECT_EQ(test->get_arg(), 1);
    EXPECT_EQ(test->get_con(), 3);
    EXPECT_EQ(test->get_redi(), 0);
}

TEST(CommandParseTest, ParenBA) {
    Connector* test = new Connector();
    std::cout << "run: echo no && (echo hello)" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(),1);
    EXPECT_EQ(test->get_arg(), 1);
    EXPECT_EQ(test->get_con(), 3);
    EXPECT_EQ(test->get_redi(), 0);
}

TEST(CommandParseTest, ParenAO) {
    Connector* test = new Connector();
    std::cout << "run: (echo no) || echo hello" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 1);
    EXPECT_EQ(test->get_arg(), 1);
    EXPECT_EQ(test->get_con(), 3);
    EXPECT_EQ(test->get_redi(), 0);
}

TEST(CommandParseTest, ParenComboA) {
    Connector* test = new Connector();
    std::cout << "run: (echo no) && (echo hello)" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 0);
    EXPECT_EQ(test->get_arg(), 0);
    EXPECT_EQ(test->get_con(), 4);
    EXPECT_EQ(test->get_redi(), 0);
}

TEST(CommandParseTest, ParenComboO) {
    Connector* test = new Connector();
    std::cout << "run: (echo no) || (echo hello)" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 0);
    EXPECT_EQ(test->get_arg(), 0);
    EXPECT_EQ(test->get_con(), 4);
    EXPECT_EQ(test->get_redi(), 0);
}

TEST(CommandParseTest, ParenE) {
    Connector* test = new Connector();
    std::cout << "run: (echo A && echo B; (echo no)) || (echo C && echo D)" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 0);
    EXPECT_EQ(test->get_arg(), 0);
    EXPECT_EQ(test->get_con(), 4);
    EXPECT_EQ(test->get_redi(), 0);
}


TEST(CommandParseTest, RediIn) {
    Connector* test = new Connector();
    std::cout << "run: a < b" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 0);
    EXPECT_EQ(test->get_arg(), 0);
    EXPECT_EQ(test->get_con(), 1);
    EXPECT_EQ(test->get_redi(), 1);
}

TEST(CommandParseTest, RediOver) {
    Connector* test = new Connector();
    std::cout << "run: a > b" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 0);
    EXPECT_EQ(test->get_arg(), 0);
    EXPECT_EQ(test->get_con(), 1);
    EXPECT_EQ(test->get_redi(), 1);
}

TEST(CommandParseTest, RediCat) {
    Connector* test = new Connector();
    std::cout << "run: a >> b" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 0);
    EXPECT_EQ(test->get_arg(), 0);
    EXPECT_EQ(test->get_con(), 1);
    EXPECT_EQ(test->get_redi(), 1);
}

TEST(CommandParseTest, RediPipe) {
    Connector* test = new Connector();
    std::cout << "run: a | b" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 0);
    EXPECT_EQ(test->get_arg(), 0);
    EXPECT_EQ(test->get_con(), 1);
    EXPECT_EQ(test->get_redi(), 1);
}

TEST(CommandParseTest, RediInParen) {
    Connector* test = new Connector();
    std::cout << "run: (a < b)" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 0);
    EXPECT_EQ(test->get_arg(), 0);
    EXPECT_EQ(test->get_con(), 2);
    EXPECT_EQ(test->get_redi(), 0);
}

TEST(CommandParseTest, RediOverParen) {
    Connector* test = new Connector();
    std::cout << "run: (a > b)" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 0);
    EXPECT_EQ(test->get_arg(), 0);
    EXPECT_EQ(test->get_con(), 2);
    EXPECT_EQ(test->get_redi(), 0);
}

TEST(CommandParseTest, RediCatParen) {
    Connector* test = new Connector();
    std::cout << "run: (a >> b)" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 0);
    EXPECT_EQ(test->get_arg(), 0);
    EXPECT_EQ(test->get_con(), 2);
    EXPECT_EQ(test->get_redi(), 0);
}
                                                                                                                                                                                   
TEST(CommandParseTest, RediPipeParen) {
    Connector* test = new Connector();
    std::cout << "run: (a | b)" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 0);
    EXPECT_EQ(test->get_arg(), 0);
    EXPECT_EQ(test->get_con(), 2);
    EXPECT_EQ(test->get_redi(), 0);
}

TEST(CommandParseTest, RediMulti1) {
    Connector* test = new Connector();
    std::cout << "run: a < b | c" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 0);
    EXPECT_EQ(test->get_arg(), 0);
    EXPECT_EQ(test->get_con(), 1);
    EXPECT_EQ(test->get_redi(), 1);
}

TEST(CommandParseTest, RediMulti2) {
    Connector* test = new Connector();
    std::cout << "run: a | b c > d" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 0);
    EXPECT_EQ(test->get_arg(), 0);
    EXPECT_EQ(test->get_con(), 1);
    EXPECT_EQ(test->get_redi(), 1);
}

TEST(CommandParseTest, RediMulti3) {
    Connector* test = new Connector();
    std::cout << "run: a b < c >> d" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 0);
    EXPECT_EQ(test->get_arg(), 0);
    EXPECT_EQ(test->get_con(), 1);
    EXPECT_EQ(test->get_redi(), 1);
}

TEST(CommandParseTest, RediCombo1) {
    Connector* test = new Connector();
    std::cout << "run: ls -a; a < b" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 1);
    EXPECT_EQ(test->get_arg(), 1);
    EXPECT_EQ(test->get_con(), 2);
    EXPECT_EQ(test->get_redi(), 1);
}

TEST(CommandParseTest, RediCombo2) {
    Connector* test = new Connector();
    std::cout << "run: ls; a | b" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 1);
    EXPECT_EQ(test->get_arg(), 0);
    EXPECT_EQ(test->get_con(), 2);
    EXPECT_EQ(test->get_redi(), 1);
}

TEST(CommandParseTest, RediCombo3) {
    Connector* test = new Connector();
    std::cout << "run: ls; a > b" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 1);
    EXPECT_EQ(test->get_arg(), 0);
    EXPECT_EQ(test->get_con(), 2);
    EXPECT_EQ(test->get_redi(), 1);
}

TEST(CommandParseTest, RediCombo4) {
    Connector* test = new Connector();
    std::cout << "run: ls; a >> b" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 1);
    EXPECT_EQ(test->get_arg(), 0);
    EXPECT_EQ(test->get_con(), 2);
    EXPECT_EQ(test->get_redi(), 1);
}

TEST(CommandParseTest, RediCombo5) {
    Connector* test = new Connector();
    std::cout << "run: a | b; ls" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 1);
    EXPECT_EQ(test->get_arg(), 0);
    EXPECT_EQ(test->get_con(), 2);
    EXPECT_EQ(test->get_redi(), 1);
}

TEST(CommandParseTest, RediCombo6) {
    Connector* test = new Connector();
    std::cout << "run: a | b || ls" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 1);
    EXPECT_EQ(test->get_arg(), 0);
    EXPECT_EQ(test->get_con(), 2);
    EXPECT_EQ(test->get_redi(), 1);
}

TEST(CommandParseTest, RediCombo7) {
    Connector* test = new Connector();
    std::cout << "run: a | b && ls" << std::endl;
    test->parse();
    EXPECT_EQ(test->get_exec(), 1);
    EXPECT_EQ(test->get_arg(), 0);
    EXPECT_EQ(test->get_con(), 2);
    EXPECT_EQ(test->get_redi(), 1);
}
*/

TEST(CommandParseTest, RunRediSimpleOverwrite) {
    Connector* test = new Connector();
    std::cout << "run: cat > test.txt" << std::endl;
    test->parse();
    EXPECT_EQ(test->run(), 0);
}

#endif // __CONNECTOR_TEST_HPP__ 
