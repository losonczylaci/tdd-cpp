#include <gtest/gtest.h>
#include <stack>

using namespace std;

TEST(stackGroup, itIsALifo) {
    stack<int> s;
    s.push(1);
    s.push(2);
    EXPECT_EQ(s.top(), 2);
    s.pop();
    EXPECT_EQ(s.top(), 1);
}

TEST(stackGroup, initialization) {
    deque<int> d = {1, 2, 3};
    stack<int, deque<int>> s1(d);
    stack<int> s2(d);
    stack<int> s3({1, 2, 3});
}

TEST(stackGroup, frontAndBack) {
    stack<int> s({1, 2, 3});
    EXPECT_EQ(s.top(), 3);
}
