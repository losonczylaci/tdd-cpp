#include <gtest/gtest.h>

class pairGroup : public ::testing::Test {
   protected:
    std::pair<int, char> p = {1, 'a'};
};

TEST_F(pairGroup, pairMembers) {
    EXPECT_EQ(p.first, 1);
    EXPECT_EQ(p.second, 'a');
}

TEST_F(pairGroup, makePair) {
    auto mp = std::make_pair(1, 'a');
    EXPECT_EQ(p, mp);
}

TEST_F(pairGroup, misc) {
    int i = 0;
    char c = 0;
    std::tie(i, c) = p;
    // std::tuple<int&, char&>(i, c) = p; //same as previous line
    EXPECT_EQ(i, 1);
    EXPECT_EQ(c, 'a');
}
