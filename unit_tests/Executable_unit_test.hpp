#ifndef __EXECUTABLE_UNIT_TEST_HPP__
#define __EXECUTABLE_UNIT_TEST_HPP__

#include "../header/Executable.hpp"
#include "../header/Connector.hpp"
//#include <filesystem.hpp>
//namespace fs = std::filesystem;
//#include <boost/filesystem.hpp>

TEST(ExecutableUnitTest, FailedExecutable) {
     Connector* test = new Connector();
     std:: cout << "run: ls -4\nexit" << std::endl;
     //test->parse();
     EXPECT_EQ(test->run(test), 0);
}


TEST(ExecutableUnitTest, ExecutableLs) {
     Connector* test = new Connector();
     std:: cout << "run: ls\nexit" << std::endl;
     //test->parse();
     EXPECT_EQ(test->run(test), 0);
}

TEST(ExecutableUnitTest, ExecutableLsA) {
     Connector* test = new Connector();
     std:: cout << "run: ls -a\nexit" << std::endl;
     //test->parse();
     EXPECT_EQ(test->run(test), 0);
}

TEST(ExecutableUnitTest, ExecutableGit) {
     Connector* test = new Connector();
     std:: cout << "run: git\nexit" << std::endl;
     //test->parse();
     EXPECT_EQ(test->run(test), 0);
}

TEST(ExecutableUnitTest, ExecutableGitStatus) {
     Connector* test = new Connector();
     std:: cout << "run: git status\nexit" << std::endl;
     //test->parse();
     EXPECT_EQ(test->run(test), 0);
}

TEST(ExecutableUnitTest, ExecutableTesteDir) {
     Connector* test = new Connector();
     std:: cout << "run: test -e src/\nexit" << std::endl;
     //test->parse();
     EXPECT_EQ(test->run(test), 0);
}

TEST(ExecutableUnitTest, ExecutableTesteFile) {
     Connector* test = new Connector();
     std:: cout << "run: test -e names.txt\nexit" << std::endl;
     //test->parse();
     EXPECT_EQ(test->run(test), 0);
}

TEST(ExecutableUnitTest, ExecutableTestd) {
     Connector* test = new Connector();
     std:: cout << "run: test -d src/\nexit" << std::endl;
     //test->parse();
     EXPECT_EQ(test->run(test), 0);
}

TEST(ExecutableUnitTest, ExecutableTestf) {
     Connector* test = new Connector();
     std:: cout << "run: test -f names.txt\nexit" << std::endl;
     //test->parse();
     EXPECT_EQ(test->run(test), 0);
}

TEST(ExecutableUnitTest, FailedExecutableTest) {
     Connector* test = new Connector();
     std:: cout << "run: test -d hi/\nexit" << std::endl;
     //test->parse();
     EXPECT_EQ(test->run(test), 0);
}

TEST(ExecutableUnitTest, MissingExecutableTest) {
     Connector* test = new Connector();
     std:: cout << "run: test src/\nexit" << std::endl;
     //test->parse();
     EXPECT_EQ(test->run(test), 0);
}

TEST(ExecutableUnitTest, SymbolicExecutableTest) {
     Connector* test = new Connector();
     std:: cout << "run: [-e src/]\nexit" << std::endl;
     //test->parse();
     EXPECT_EQ(test->run(test), 0);
}

TEST(ExecutableUnitTest, AbsoluteExecutableTest) {
     Connector* test = new Connector();
     char cwd[256];
     if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd() error");
     }
     else {
        printf("run: test -e  %s\n", cwd);
        std::cout << "exit" << std:: endl;
        //std:: cout << "run: test -e" << %s\n << std::endl;
        test->parse();
        EXPECT_EQ(test->run(test), 0);
     }
}

TEST(ExecutableUnitTest, ExitExecutable) {
     Connector* test = new Connector();
     std:: cout << "run: exit" << std::endl;
     //test->parse();
     EXPECT_EQ(test->run(test), 0);
}

#endif // __EXECUTABLE_UNIT_TEST_HPP__
