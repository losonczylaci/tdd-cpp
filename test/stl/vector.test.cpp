#include <gtest/gtest.h>
#include <utility>
#include <vector>

using namespace std;

TEST(vectorGroup, attributes) {
    vector<int> v = {1, 2, 3, 4, 5, 6};
    EXPECT_EQ(1, v.front());
    EXPECT_EQ(6, v.back());
    EXPECT_EQ(2, v.at(1));
    EXPECT_EQ(2, v[1]);
    EXPECT_EQ(6u, v.size());
}

TEST(vectorGroup, pushAndPop) {
    vector<int> v = {1};
    v.push_back(10);
    EXPECT_EQ(10, v.back());
    v.pop_back();
    EXPECT_EQ(1, v.back());
}

TEST(vectorGroup, insertAndErase) {
    vector<int> v = {1};
    v.insert(v.begin() + 1, 2);
    EXPECT_EQ(2, v.back());

    v.erase(v.begin() + 1);
    EXPECT_EQ(1, v.back());

    v.insert(v.begin() + 1, {2, 3, 4, 5});
    EXPECT_EQ(5, v.back());
    EXPECT_EQ(5u, v.size());
}

TEST(vectorGroup, creation) {
    int ia[] = {1, 2, 3};
    vector<int> va(ia, ia + 3);
    EXPECT_EQ(va, vector<int>({1, 2, 3}));

    vector<int> v(5, 1);
    EXPECT_EQ(v, vector<int>({1, 1, 1, 1, 1}));

    vector<int> vCopyCtor = v;
    EXPECT_EQ(v, vCopyCtor);

    vector<int> vMoveCtor = std::move(v);
    EXPECT_NE(v, vCopyCtor);
}
