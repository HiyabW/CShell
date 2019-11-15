#ifndef __EXECUTABLE_UNIT_TEST_HPP__
#define __EXECUTABLE_UNIT_TEST_HPP__

#include "../header/Executable.hpp"
#include "../header/Connector.hpp"

TEST(ExecutableUnitTest, ExecutableLs) {
     Connector* test = new Connector();
     std:: cout << "run: ls" << std::endl;
     EXPECT_EQ(test->run(test), 0);
};

TEST(ExecutableUnitTest, ExecutableLsA) {
     Connector* test = new Connector();
     std:: cout << "run: ls -a" << std::endl;
     EXPECT_EQ(test->run(test), 0);
};

TEST(ExecutableUnitTest, ExecutableGit) {
     Connector* test = new Connector();
     std:: cout << "run: git" << std::endl;
     EXPECT_EQ(test->run(test), 0);
};

TEST(ExecutableUnitTest, ExecutableGitStatus) {
     Connector* test = new Connector();
     std:: cout << "run: git status" << std::endl;
     EXPECT_EQ(test->run(test), 0);
};

TEST(ExecutableUnitTest, ExecutableMkdir) {
     Connector* test = new Connector();
     std:: cout << "run: mkdir" << std::endl;
     EXPECT_EQ(test->run(test), 0);
};
#endif
