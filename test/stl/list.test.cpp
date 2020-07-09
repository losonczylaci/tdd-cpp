#include <gtest/gtest.h>
#include <list>
#include <utility>

using namespace std;

class listGroup : public ::testing::Test {
   protected:
    list<int> l = {1, 2, 3};
};

TEST_F(listGroup, listCreation) {
    auto lCopy = l;
    EXPECT_EQ(lCopy, l);

    auto lMove = std::move(lCopy);
    EXPECT_EQ(lCopy.size(), 0u);
    EXPECT_EQ(l, lMove);
}

TEST_F(listGroup, listBackFront) {
    EXPECT_EQ(l.back(), 3);
    EXPECT_EQ(l.front(), 1);
}

TEST_F(listGroup, listInsert) {
    l.insert(l.begin(), 111);
    EXPECT_EQ(l.front(), 111);
    l.insert(l.begin(), {109, 110});
    EXPECT_EQ(l, list<int>({109, 110, 111, 1, 2, 3}));
}

TEST_F(listGroup, listAssign) {
    l.assign(3, 1);
    EXPECT_EQ(l, list<int>({1, 1, 1}));
    l.assign({3, 2, 1});
    EXPECT_EQ(l, list<int>({3, 2, 1}));
}

TEST_F(listGroup, capacity) {
    EXPECT_EQ(l.empty(), false);
    EXPECT_EQ(l.size(), 3u);
    EXPECT_NE(l.max_size(), 3u);
    l.clear();
    EXPECT_EQ(l.empty(), true);
}
