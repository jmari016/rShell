CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(rshell
    src/main.cpp
    src/Execute.cpp
    src/ExecuteOR.cpp
    src/ExecuteAND.cpp
    src/ExecuteSEMI.cpp
    src/piping.cpp 
    src/InputRedirect.cpp
    src/OutputRedirect.cpp    
    src/OutputRedirect2.cpp
)

ADD_EXECUTABLE(test
    unit_tests/unitTest.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
