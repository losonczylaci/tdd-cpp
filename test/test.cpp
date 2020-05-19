
#include <gtest/gtest.h>
#include <rectangle.hpp>

TEST(test, test1) {
    Rectangle rect(1,2);
    ASSERT_EQ(2, rect.getArea());
};