#include <gtest/gtest.h>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

class setGroup : public ::testing::Test {
   protected:
    set<string> s = {"one", "two", "three"};
};

TEST_F(setGroup, find) {
    auto iter = s.find("one");
    EXPECT_EQ(*iter, "one");

    iter = s.find("won't find");
    EXPECT_EQ(iter, s.end());
};

TEST_F(setGroup, count) {
    EXPECT_EQ(s.count("three"), 1u);
    EXPECT_EQ(s.size(), 3u);
    EXPECT_FALSE(s.empty());
}

TEST_F(setGroup, insert) {
    auto result = s.insert("one");
    EXPECT_EQ(result.first, s.find("one"));
    EXPECT_EQ(result.second, false);

    result = s.insert("four");
    EXPECT_EQ(result.first, s.find("four"));
    EXPECT_EQ(result.second, true);
}

TEST_F(setGroup, test) {
    s.erase(s.find("three"));
    EXPECT_EQ(s.end(), s.find("three"));
}

TEST_F(setGroup, setIsSorted) {
    EXPECT_EQ(is_sorted(s.begin(), s.end()), true);
}
