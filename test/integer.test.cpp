#include <gtest/gtest.h>
#include <integer.hpp>
#include <stdexcept>

class IntGroup : public ::testing::Test {
   protected:
    const Int i1 = 1;
    const Int i2 = 2;
};

TEST_F(IntGroup, shouldHaveSetterAndGetter) {
    Int i5 = 5;
    ASSERT_EQ(5, i5.getValue());
    i5.setValue(6);
    ASSERT_EQ(6, i5.getValue());
}

TEST_F(IntGroup, eqToOperator) {
    ASSERT_TRUE(i1 == i1);
    ASSERT_TRUE(i1 == 1);
    ASSERT_TRUE(1 == i1);
}

TEST_F(IntGroup, notEqToOperator) {
    ASSERT_TRUE(i1 != i2);
    ASSERT_TRUE(i1 != 2);
    ASSERT_TRUE(1 != i2);
}

TEST_F(IntGroup, addOperator) {
    ASSERT_EQ(i1 + i1, 2);
    ASSERT_EQ(i1 + 1, 2);
    ASSERT_EQ(1 + i1, 2);
}

TEST_F(IntGroup, subOperator) {
    ASSERT_EQ(i2 - i1, 1);
    ASSERT_EQ(i2 - 1, 1);
    ASSERT_EQ(2 - i1, 1);
}

TEST_F(IntGroup, mulOperator) {
    ASSERT_EQ(i1 * i2, 2);
    ASSERT_EQ(i1 * 2, 2);
    ASSERT_EQ(1 * i2, 2);
}

TEST_F(IntGroup, divOperator) {
    ASSERT_EQ(i2 / i2, 1);
    ASSERT_EQ(i2 / 2, 1);
    ASSERT_EQ(2 / i2, 1);
    ASSERT_ANY_THROW(i2 / 0);
}
