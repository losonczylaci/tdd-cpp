#include <gtest/gtest.h>

class lambdaGroup : public ::testing::Test {
   protected:
    int _member = 100;
};

TEST_F(lambdaGroup, lambda) {
    EXPECT_EQ(1, ([](void) -> int { return 1; })());
    EXPECT_EQ(1, ([](void) { return 1; })());
}

TEST_F(lambdaGroup, lambdaCaptureThis) {
    ([this](void) { _member = 1; })();
    EXPECT_EQ(1, _member);
}

TEST_F(lambdaGroup, lambdaByCopyCapture) {
    int a = 1;
    auto lambda = [a](void) {
        // a = 1; // does not compile
        return a;
    };
    EXPECT_EQ(1, lambda());
}

TEST_F(lambdaGroup, lambdaByReferenceCapture) {
    int a;
    ([&a](void) { a = 1; })();
    EXPECT_EQ(1, a);
}

TEST_F(lambdaGroup, lambdaDefaultReferenceCapture) {
    int a, b;
    ([&](void) {
        a = 1;
        b = 2;
    })();
    EXPECT_EQ(a, 1);
    EXPECT_EQ(b, 2);
}

TEST_F(lambdaGroup, lambdaDefaultByCopyCapture) {
    int a = 1, b = 2, c = 0;
    ([=, &c](void) { c = a + b; })();
    EXPECT_EQ(c, 3);
}

TEST_F(lambdaGroup, lambdaMixedCapture) {
    int a = 1, b = 2, c = 1;
    ([&, c, this]() {
        a += c;
        b += c;
        _member += c;
        // c = 3;  // won't compile
    })();
    EXPECT_EQ(a, 2);
    EXPECT_EQ(b, 3);
    EXPECT_EQ(_member, 101);
}

enum class Color { Red = 0, Green, Blue };

TEST_F(lambdaGroup, switchInLambda) {
    auto color = Color::Red;
    auto colorCode = [&]() {
        switch (color) {
            case Color::Red:
                return 10;
            case Color::Green:
                return 20;
            case Color::Blue:
                return 30;
            default:
                return 0;
        }
    }();
    EXPECT_EQ(colorCode, 10);
}
