CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
    src/unit_test.cpp
    src/Connector.cpp
    src/Executable.cpp
    src/Redirection.cpp
)

ADD_EXECUTABLE(rshell
    src/main_rshell.cpp
    src/Connector.cpp
    src/Executable.cpp
    src/Redirection.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)

