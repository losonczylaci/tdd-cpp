#include <gtest/gtest.h>

template <int _a, int _b>
struct Rectangle {
    int a = _a;
    int b = _b;
    int permiter = (a + b) * 2;
    int area = a * b;
};

TEST(tmpGroup, testRectangle) {
    Rectangle<2, 4> rect;
    EXPECT_EQ(rect.a, 2);
    EXPECT_EQ(rect.b, 4);
    EXPECT_EQ(rect.permiter, 12);
    EXPECT_EQ(rect.area, 8);
}

template <int toCube>
struct Cube {
    enum { value = toCube * toCube * toCube };
};

TEST(tmpGroup, testCube) {
    EXPECT_EQ(27, Cube<3>::value);
    EXPECT_EQ(125, Cube<5>::value);
}

template <int input, int sum = 1>
struct Factorial : Factorial<input - 1, input * sum> {};

template <int sum>
struct Factorial<1, sum> {
    enum { value = sum };
};

TEST(tmpGroup, testFactorial) {
    EXPECT_EQ(24, Factorial<4>::value);
}
