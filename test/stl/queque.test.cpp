#include <gtest/gtest.h>
#include <queue>

using namespace std;

TEST(queueGroup, initialization) {
    deque<int> d = {1, 2, 3, 4};  // deque default container
    queue<int, deque<int>> q1(d);
    queue<int> q2(d);
    queue<int> q3({1, 2, 3});
    auto q4 = queue<int>(d);
    auto q5 = queue<int>({1, 2, 3});
}

TEST(queueGroup, itIsAFifo) {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    EXPECT_EQ(q.front(), 1);
    q.pop();
    EXPECT_EQ(q.front(), 2);
    q.pop();
    EXPECT_EQ(q.front(), 3);
}

TEST(quequeGroup, backAndFront) {
    queue<int> q({1, 2, 3});
    EXPECT_EQ(q.front(), 1);
    EXPECT_EQ(q.back(), 3);
}
