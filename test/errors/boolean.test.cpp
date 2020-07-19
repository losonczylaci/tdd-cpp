#include <gtest/gtest.h>

struct Person {
    int age;
    bool isOkay;
};

TEST(randomGroup, wontFail) {
    Person p;
    int* ap = &p.age;
    *(++ap) = 1;  // pointer reaches isOkay memory address 0b0000001
    EXPECT_EQ(true, p.isOkay);
}

TEST(randomGroup, willFail) {
    Person p;
    int* ap = &p.age;
    *(++ap) = 11;  // pointer reaches isOkay memory address
    EXPECT_EQ(true, p.isOkay);
}