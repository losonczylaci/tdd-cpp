#include <gtest/gtest.h>
#include <string>

template <typename T>
T rcatenate(T first) {
    return first;
}

template <typename T, typename... Args>
T rcatenate(T first, Args... args) {
    return rcatenate(args...) + " " + first;
}

TEST(variadicGroup, reverseCatenate) {
    std::string a = "a", b = "b";
    EXPECT_EQ("b a", rcatenate(a, b));
}

template <typename T>
T summer(T first) {
    return first;
}
template <typename T, typename... Args>
T summer(T first, Args... args) {
    return first + summer(args...);
}

TEST(variadicGroup, intSum) {
    int a = 1, b = 2, c = 3;
    EXPECT_EQ(6, summer(a, b, c));
}
