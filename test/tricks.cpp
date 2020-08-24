#include <gtest/gtest.h>

TEST(tricksGroup, curry) {
    auto curryFunc = [](int a) {
        return [a](int b) { return [a, b](int c) { return a * b * c; }; };
    };
    EXPECT_EQ(6, curryFunc(1)(2)(3));
    EXPECT_EQ(24, curryFunc(2)(3)(4));
}

TEST(tricksGroup, mutableLambda) {
    auto incrementer = []() {
        auto increment = 0;
        return [increment]() mutable { return ++increment; };
    };
    auto myInc = incrementer();
    EXPECT_EQ(1, myInc());
    EXPECT_EQ(2, myInc());
}

class Class {
   public:
    Class& method1() {
        return *this;
    }
    Class& method2() {
        return *this;
    }
    int method3() {
        return 2;
    }
};

TEST(tricksGroup, methodChaingin) {
    Class c;
    EXPECT_EQ(2, c.method1().method2().method3());
}
