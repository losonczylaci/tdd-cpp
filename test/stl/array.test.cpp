#include <gtest/gtest.h>

using namespace std;

class arrayGroup : public ::testing::Test {
   protected:
    array<int, 3> a = {1, 2, 3};
};

TEST_F(arrayGroup, elementAccess) {
    EXPECT_EQ(a.at(1), 2);
    EXPECT_EQ(a[1], 2);
    EXPECT_EQ(get<1>(a), 2);
    EXPECT_EQ(a.front(), 1);
    EXPECT_EQ(a.back(), 3);
}

TEST_F(arrayGroup, size) {
    EXPECT_EQ(a.size(), 3u);
    EXPECT_EQ(a.max_size(), 3u);
}

TEST_F(arrayGroup, fillAndCreation) {
    a.fill(1);
    array<int, 3> a1{1, 1, 1};
    auto a2 = array<int, 3>{1, 1, 1};
    array<int, 3> a3 = {1, 1, 1};
    EXPECT_EQ(a, a1);
    EXPECT_EQ(a, a2);
    EXPECT_EQ(a, a3);
}
