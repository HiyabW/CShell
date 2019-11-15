CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
    ~/assignment-yabbie_ruth/src/unit_test.cpp
    ~/assignment-yabbie_ruth/src/Connector.cpp
    ~/assignment-yabbie_ruth/src/Executable.cpp
)

ADD_EXECUTABLE(rshell
    ~/assignment-yabbie_ruth/src/main_rshell.cpp
    ~/assignment-yabbie_ruth/src/Connector.cpp
    ~/assignment-yabbie_ruth/src/Executable.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)

