#include <gtest/gtest.h>
#include <algorithm>
#include <vector>

using namespace std;

class algorithmGroup : public ::testing::Test {
   protected:
    vector<int> v = {1, 2, 3, 4, 5};
};

TEST_F(algorithmGroup, binarySearch) {
    EXPECT_TRUE(binary_search(v.begin(), v.end(), 5));
    EXPECT_FALSE(binary_search(v.begin(), v.end(), 100));
}

template <typename T>
bool isLessThen10(const T value) {
    return value < static_cast<T>(10);
}

template <typename T>
bool isLessThen5(const T value) {
    return value < static_cast<T>(5);
}

TEST_F(algorithmGroup, allOf) {
    EXPECT_TRUE(all_of(v.begin(), v.end(), isLessThen10<int>));
    EXPECT_FALSE(all_of(v.begin(), v.end(), isLessThen5<int>));
}

TEST_F(algorithmGroup, anyOf) {
    EXPECT_TRUE(any_of(v.begin(), v.end(), isLessThen5<int>));
}

TEST_F(algorithmGroup, noneOf) {
    EXPECT_FALSE(none_of(v.begin(), v.end(), isLessThen5<int>));
}

TEST_F(algorithmGroup, find) {
    EXPECT_EQ(v.end() - 1, find(v.begin(), v.end(), 5));
    EXPECT_EQ(v.end(), find(v.begin(), v.end(), 100));
}

bool isOdd(const int value) { return (value % 2) == 1; }

TEST_F(algorithmGroup, findIf) {
    auto result = find_if(v.begin(), v.end(), isOdd);
    EXPECT_EQ(result, v.begin());
}

TEST_F(algorithmGroup, findIfNot) {
    auto result = find_if_not(v.begin(), v.end(), isOdd);
    EXPECT_EQ(result, v.begin() + 1);
}

TEST_F(algorithmGroup, search) {
    vector<int> searched = {1, 2, 3};
    auto it = search(v.begin(), v.end(), searched.begin(), searched.end());
    EXPECT_EQ(it, v.begin());
}

TEST_F(algorithmGroup, count) {
    EXPECT_EQ(1, count(v.begin(), v.end(), 1));
    v.push_back(1);
    EXPECT_EQ(2, count(v.begin(), v.end(), 1));
}

TEST_F(algorithmGroup, replace) {
    v.push_back(1);
    replace(v.begin(), v.end(), 1, 99);
    EXPECT_EQ(v, vector<int>({99, 2, 3, 4, 5, 99}));
}

TEST_F(algorithmGroup, replaceIf) {
    replace_if(v.begin(), v.end(), isOdd, 99);
    EXPECT_EQ(v, vector<int>({99, 2, 99, 4, 99}));
}