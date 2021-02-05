#include <gtest/gtest.h>
#include "add.hpp"

TEST(addGroup, addsNumbers) {
    EXPECT_EQ(2, add(1, 1));
}