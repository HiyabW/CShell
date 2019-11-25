#ifndef __EXECUTABLE_UNIT_TEST_HPP__
#define __EXECUTABLE_UNIT_TEST_HPP__

#include "../header/Executable.hpp"
#include "../header/Connector.hpp"

TEST(ExecutableUnitTest, FailedExecutable) {
     Connector* test = new Connector();
     std:: cout << "run: ls -4" << std::endl;
     test->parse();
     EXPECT_EQ(test->run(test), 1);
}

TEST(ExecutableUnitTest, ExecutableLs) {
     Connector* test = new Connector();
     std:: cout << "run: ls" << std::endl;
     test->parse();
     EXPECT_EQ(test->run(test), 0);
}

TEST(ExecutableUnitTest, ExecutableLsA) {
     Connector* test = new Connector();
     std:: cout << "run: ls -a" << std::endl;
     test->parse();
     EXPECT_EQ(test->run(test), 0);
}

TEST(ExecutableUnitTest, ExecutableGit) {
     Connector* test = new Connector();
     std:: cout << "run: git" << std::endl;
     test->parse();
     EXPECT_EQ(test->run(test), 1);
}

TEST(ExecutableUnitTest, ExecutableGitStatus) {
     Connector* test = new Connector();
     std:: cout << "run: git status" << std::endl;
     test->parse();
     EXPECT_EQ(test->run(test), 0);
}

/* TEST(ExecutableUnitTest, ExecutableMkdir) {
     Connector* test = new Connector();
     std:: cout << "run: mkdir" << std::endl;
     test->parse();
     EXPECT_EQ(test->run(test), 0);
}
*/

TEST(ExecutableUnitTest, ExecutableTesteDir) {
     Connector* test = new Connector();
     std:: cout << "run: test -e src/" << std::endl;
     test->parse();
     EXPECT_EQ(test->run(test), 0);
}

TEST(ExecutableUnitTest, ExecutableTesteFile) {
     Connector* test = new Connector();
     std:: cout << "run: test -e names.txt" << std::endl;
     test->parse();
     EXPECT_EQ(test->run(test), 0);
}

TEST(ExecutableUnitTest, ExecutableTestd) {
     Connector* test = new Connector();
     std:: cout << "run: test -d src/" << std::endl;
     test->parse();
     EXPECT_EQ(test->run(test), 0);
}

TEST(ExecutableUnitTest, ExecutableTestf) {
     Connector* test = new Connector();
     std:: cout << "run: test -f names.txt" << std::endl;
     test->parse();
     EXPECT_EQ(test->run(test), 0);
}
TEST(ExecutableUnitTest, FailedExecutableTest) {
     Connector* test = new Connector();
     std:: cout << "run: test -d hi/" << std::endl;
     test->parse();
     EXPECT_EQ(test->run(test), 1);
}

TEST(ExecutableUnitTest, MissingExecutableTest) {
     Connector* test = new Connector();
     std:: cout << "run: test src/" << std::endl;
     test->parse();
     EXPECT_EQ(test->run(test), 0);
}

#endif // __EXECUTABLE_UNIT_TEST_HPP__
