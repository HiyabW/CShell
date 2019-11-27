#ifndef __EXECUTABLE_UNIT_TEST_HPP__
#define __EXECUTABLE_UNIT_TEST_HPP__

#include "../header/Executable.hpp"
#include "../header/Connector.hpp"

TEST(ExecutableUnitTest, FailedExecutable) {
     Connector* test = new Connector();
     std:: cout << "run: ls -4; exit" << std::endl;
     //test->parse();
     EXPECT_EQ(test->run(test), 1);
}


TEST(ExecutableUnitTest, ExecutableLs) {
     Connector* test = new Connector();
     std:: cout << "run: ls; exit" << std::endl;
     //test->parse();
     EXPECT_EQ(test->run(test), 0);
}

TEST(ExecutableUnitTest, ExecutableLsA) {
     Connector* test = new Connector();
     std:: cout << "run: ls -a; exit" << std::endl;
     //test->parse();
     EXPECT_EQ(test->run(test), 0);
}

TEST(ExecutableUnitTest, ExecutableGit) {
     Connector* test = new Connector();
     std:: cout << "run: git; exit" << std::endl;
     //test->parse();
     EXPECT_EQ(test->run(test), 1);
}

TEST(ExecutableUnitTest, ExecutableGitStatus) {
     Connector* test = new Connector();
     std:: cout << "run: git status; exit" << std::endl;
     //test->parse();
     EXPECT_EQ(test->run(test), 0);
}

TEST(ExecutableUnitTest, ExecutableTesteDir) {
     Connector* test = new Connector();
     std:: cout << "run: test -e src/ ; exit" << std::endl;
     //test->parse();
     EXPECT_EQ(test->run(test), 0);
}

TEST(ExecutableUnitTest, ExecutableTesteFile) {
     Connector* test = new Connector();
     std:: cout << "run: test -e names.txt ; exit" << std::endl;
     //test->parse();
     EXPECT_EQ(test->run(test), 0);
}

TEST(ExecutableUnitTest, ExecutableTestd) {
     Connector* test = new Connector();
     std:: cout << "run: test -d src/ ; exit" << std::endl;
     //test->parse();
     EXPECT_EQ(test->run(test), 0);
}

TEST(ExecutableUnitTest, ExecutableTestf) {
     Connector* test = new Connector();
     std:: cout << "run: test -f names.txt ; exit" << std::endl;
     //test->parse();
     EXPECT_EQ(test->run(test), 0);
}

TEST(ExecutableUnitTest, FailedExecutableTest) {
     Connector* test = new Connector();
     std:: cout << "run: test -d hi/ ; exit" << std::endl;
     //test->parse();
     EXPECT_EQ(test->run(test), 1);
}

TEST(ExecutableUnitTest, MissingExecutableTest) {
     Connector* test = new Connector();
     std:: cout << "run: test src/ ; exit" << std::endl;
     //test->parse();
     EXPECT_EQ(test->run(test), 0);
}

TEST(ExecutableUnitTest, ExitExecutable) {
     Connector* test = new Connector();
     std:: cout << "run: exit" << std::endl;
     //test->parse();
     EXPECT_EQ(test->run(test), 0);
}

#endif // __EXECUTABLE_UNIT_TEST_HPP__
