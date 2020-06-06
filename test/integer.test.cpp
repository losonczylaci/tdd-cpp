#include <gtest/gtest.h>
#include <integer.hpp>
#include <stdexcept>
#include <string>

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

TEST_F(IntGroup, stringConversionOperator) {
    ASSERT_EQ("1", static_cast<std::string>(i1));
    std::string str = "No. ";
    str += i1;
    ASSERT_EQ("No. 1", str);
}

TEST_F(IntGroup, ostreamOperator) {
    std::stringstream out;
    out << "Value: " << i1;
    ASSERT_EQ("Value: 1", out.str());
}

TEST_F(IntGroup, functor) {
    ASSERT_EQ(2, i1(2));
    ASSERT_EQ(4, i2(2));
}

TEST_F(IntGroup, increments) {
    Int i = 10;
    ASSERT_EQ(11, ++i);
    ASSERT_EQ(11, i);
    ASSERT_EQ(11, i++);
    ASSERT_EQ(12, i);
}
