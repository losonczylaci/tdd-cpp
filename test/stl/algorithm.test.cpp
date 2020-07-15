#include <gtest/gtest.h>
#include <algorithm>
#include <vector>

using namespace std;

class algorithmGroup : public ::testing::Test {
   protected:
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int> vu = {1, 5, 3, 2, 4};
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

TEST_F(algorithmGroup, remove) {
    auto it = remove(v.begin(), v.end(), 1);
    EXPECT_EQ(v.end() - 1, it);
    v.resize(it - v.begin());
    EXPECT_EQ(v, vector<int>({2, 3, 4, 5}));
}

TEST_F(algorithmGroup, removeIf) {
    auto last = remove_if(v.begin(), v.end(), isOdd);
    v.resize(last - v.begin());
    EXPECT_EQ(v, vector<int>({2, 4}));
}

TEST_F(algorithmGroup, copy) {
    vector<int> copied(v.size());
    copy(v.begin(), v.end(), copied.begin());
    EXPECT_EQ(copied, v);
}

TEST_F(algorithmGroup, copyBackward) {
    vector<int> copied(v.size() + 2, 0);
    copy_backward(v.begin(), v.end(), copied.end());
    EXPECT_EQ(copied, vector<int>({0, 0, 1, 2, 3, 4, 5}));
}

TEST_F(algorithmGroup, reverseCopy) {
    vector<int> copied(v.size());
    reverse_copy(v.begin(), v.end(), copied.begin());
    EXPECT_EQ(copied, vector<int>({5, 4, 3, 2, 1}));
}

TEST_F(algorithmGroup, reverse) {
    reverse(v.begin(), v.end());
    EXPECT_EQ(v, vector<int>({5, 4, 3, 2, 1}));
}

TEST_F(algorithmGroup, fill) {
    fill(v.begin(), v.end() - 2, 0);
    EXPECT_EQ(v, vector<int>({0, 0, 0, 4, 5}));
}

TEST_F(algorithmGroup, fillN) {
    fill_n(v.begin(), 2, 0);
    EXPECT_EQ(v, vector<int>({0, 0, 3, 4, 5}));
}

TEST_F(algorithmGroup, generate) {
    generate(v.begin(), v.end(), []() { return rand(); });
    EXPECT_NE(v, vector<int>({1, 2, 3, 4, 5}));
}

TEST_F(algorithmGroup, partition) {
    partition(v.begin(), v.end(), isOdd);
    EXPECT_EQ(v, vector<int>({1, 5, 3, 4, 2}));
}

TEST_F(algorithmGroup, stablePartition) {
    stable_partition(v.begin(), v.end(), isOdd);
    EXPECT_EQ(v, vector<int>({1, 3, 5, 2, 4}));
}

TEST_F(algorithmGroup, partitionCopy) {
    auto size = count_if(v.begin(), v.end(), isOdd);
    vector<int> odds(size), evens(v.size() - size);
    partition_copy(v.begin(), v.end(), odds.begin(), evens.begin(), isOdd);
    EXPECT_EQ(odds, vector<int>({1, 3, 5}));
    EXPECT_EQ(evens, vector<int>({2, 4}));
}

TEST_F(algorithmGroup, sort) {
    sort(vu.begin(), vu.end());
    EXPECT_EQ(vu, v);
}

bool isLessThan(int a, int b) { return a < b; }
bool isGreaterThan(int a, int b) { return a > b; }

TEST_F(algorithmGroup, customSort) {
    sort(vu.begin(), vu.end(), isLessThan);
    EXPECT_EQ(vu, v);
}

TEST_F(algorithmGroup, merge) {
    vector<int> result(vu.size() + v.size());
    sort(v.begin(), v.end());
    sort(vu.begin(), vu.end());
    merge(v.begin(), v.end(), vu.begin(), vu.end(), result.begin());
    EXPECT_EQ(result, vector<int>({1, 1, 2, 2, 3, 3, 4, 4, 5, 5}));

    sort(v.begin(), v.end(), isGreaterThan);
    sort(vu.begin(), vu.end(), isGreaterThan);
    merge(v.begin(), v.end(), vu.begin(), vu.end(), result.begin(),
          isGreaterThan);
    EXPECT_EQ(result, vector<int>({5, 5, 4, 4, 3, 3, 2, 2, 1, 1}));
}