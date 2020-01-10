#ifndef __RSHELL_TEST_HPP__
#define __RSHELL_TEST_HPP__

#include "gtest/gtest.h"
#include "base.hpp"
#include "rShell.cpp"
#include <cmath>

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}
TEST(OpTest, OpStringifyNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->stringify(), "8.000000");
}

TEST(OpTest, OpEvaluateZero) {
    Op* test = new Op(0);
    EXPECT_EQ(test->evaluate(), 0);
}
TEST(OpTest, OpStringifyZero) {
    Op* test = new Op(0);

