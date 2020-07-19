#include <gtest/gtest.h>
#include <deque>

using namespace std;

class dequeGroup : public ::testing::Test {
   protected:
    deque<int> d = {1, 2, 3};
};

TEST_F(dequeGroup, elementAccess) {
    EXPECT_EQ(d.front(), 1);
    EXPECT_EQ(d.back(), 3);
    EXPECT_EQ(d.at(1), 2);
    EXPECT_EQ(d[1], 2);
}

TEST_F(dequeGroup, iterators) {
    EXPECT_EQ(d.begin()[0], 1);
    EXPECT_EQ(d.rbegin()[0], 3);
    EXPECT_EQ(d.begin()[1], 2);
    EXPECT_EQ(d.rbegin()[1], 2);
    EXPECT_EQ(d.end()[-1], 3);
    EXPECT_EQ(d.rend()[-1], 1);
    EXPECT_EQ(d.end()[-2], 2);
    EXPECT_EQ(d.rend()[-2], 2);
}

TEST_F(dequeGroup, size) {
    EXPECT_EQ(d.size(), 3u);
    EXPECT_GT(d.max_size(), 3u);
}

TEST_F(dequeGroup, pushPopBack) {
    d.push_back(4);
    EXPECT_EQ(d.back(), 4);
    d.pop_back();
    EXPECT_EQ(d.back(), 3);
}

TEST_F(dequeGroup, pushPopFront) {
    d.push_front(0);
    EXPECT_EQ(d.front(), 0);
    d.pop_front();
    EXPECT_EQ(d.front(), 1);
}

TEST_F(dequeGroup, eraseAndEmpty) {
    d.erase(d.begin(), d.end());
    EXPECT_TRUE(d.empty());
}

TEST_F(dequeGroup, insert) {
    d.insert(d.begin() + 1, 11);
    EXPECT_EQ(d.begin()[1], 11);

    d.insert(d.end(), {4, 5});
    EXPECT_EQ(d.rbegin()[1], 4);
    EXPECT_EQ(d.rbegin()[0], 5);
}

TEST_F(dequeGroup, clear) {
    d.clear();
    EXPECT_EQ(d.size(), 0u);
}
