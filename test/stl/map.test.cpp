#include <gtest/gtest.h>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

class mapGroup : public ::testing::Test {
   protected:
    map<int, string> m = {{1, "cat"}, {2, "dog"}};
};

TEST_F(mapGroup, elementAccess) {
    EXPECT_EQ(m[1], "cat");
    EXPECT_EQ(m[2], "dog");
    EXPECT_EQ(m.at(2), "dog");
}

TEST_F(mapGroup, findBasedOnKey) {
    auto iter = m.find(1);
    EXPECT_NE(iter, m.end());

    auto result = m.find(99);
    EXPECT_EQ(m.end(), result);
}

TEST_F(mapGroup, findBasedOnMappedValue) {
    auto result = find_if(m.begin(), m.end(), [](const pair<int, string>& el) {
        return (el.second == "cat");
    });
    EXPECT_EQ(result, m.find(1));
}

TEST_F(mapGroup, erase) {
    auto size = m.erase(1);
    EXPECT_EQ(size, 1u);
}

TEST_F(mapGroup, capacity) {
    EXPECT_EQ(m.size(), 2u);
    EXPECT_FALSE(m.empty());
    m.clear();
    EXPECT_TRUE(m.empty());
}

TEST_F(mapGroup, count) { EXPECT_EQ(m.count(1), 1u); }

TEST_F(mapGroup, insert) {
    auto result = m.insert({1, "cow"});
    EXPECT_EQ(result.first, m.find(1));
    EXPECT_EQ(result.second, false);

    result = m.insert({3, "cow"});
    EXPECT_EQ(result.first, m.find(3));
    EXPECT_EQ(result.second, true);
}
