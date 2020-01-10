#include "gtest/gtest.h"

#include "unitTest.hpp"
#include "../src/Execute.cpp"
#include "../src/ExecuteAND.cpp"
#include "../src/ExecuteOR.cpp"
#include "../src/ExecuteSEMI.cpp"
#include "../src/piping.cpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
