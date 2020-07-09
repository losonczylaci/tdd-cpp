#include <gtest/gtest.h>
#include <algorithm>
#include <vector>

using namespace std;
class functorGroup : public ::testing::Test {
   protected:
    vector<int> in = {1, 2, 3};
    vector<int> out = {0, 0, 0};
    functorGroup() {}
};

#define binaryTransform(i1, i2, o, op) \
    transform(i1.begin(), i1.end(), i2.begin(), o.begin(), op)

#define unaryTransform(i1, o, op) transform(i1.begin(), i1.end(), o.begin(), op)

TEST_F(functorGroup, minus) {
    minus<int> f;
    binaryTransform(in, in, out, f);
    EXPECT_EQ(out, vector<int>({0, 0, 0}));
}

TEST_F(functorGroup, plus) {
    plus<int> f;
    binaryTransform(in, in, out, f);
    EXPECT_EQ(out, vector<int>({2, 4, 6}));
}

TEST_F(functorGroup, multiplies) {
    multiplies<int> f;
    binaryTransform(in, in, out, f);
    EXPECT_EQ(out, vector<int>({1, 4, 9}));
}

TEST_F(functorGroup, divides) {
    divides<int> f;
    binaryTransform(in, in, out, f);
    EXPECT_EQ(out, vector<int>({1, 1, 1}));
}

TEST_F(functorGroup, modulus) {
    modulus<int> f;
    binaryTransform(in, in, out, f);
    EXPECT_EQ(out, vector<int>({0, 0, 0}));
}

TEST_F(functorGroup, negate) {
    negate<int> f;
    unaryTransform(in, out, f);
    EXPECT_EQ(out, vector<int>({-1, -2, -3}));
}

template <typename T>
struct add10 : public unary_function<T, T> {
    T operator()(T in) const { return in + static_cast<T>(10); }
};

TEST_F(functorGroup, customInt) {
    add10<int> f;
    unaryTransform(in, out, f);
    EXPECT_EQ(out, vector<int>({11, 12, 13}));
}

TEST_F(functorGroup, customFloat) {
    vector<float> vIn = {1.1f, 2.1f, 3.1f};
    vector<float> vOut = {0.0f, 0.0f, 0.0f};
    add10<float> f;
    unaryTransform(vIn, vOut, f);
    EXPECT_EQ(vOut, vector<float>({11.1f, 12.1f, 13.1f}));
}
