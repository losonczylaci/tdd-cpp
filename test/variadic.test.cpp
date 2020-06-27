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
