#include <gtest/gtest.h>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class transGroup : public ::testing::Test {
   protected:
    vector<int> in = {1, 2, 3};
    string s = "rANDOM tEXT";
};

template <typename T>
class Accumulate {
    T _acc = 0;

   public:
    Accumulate(T n) : _acc(n) {}
    T operator()(int n) {
        _acc += n;
        return _acc;
    }
};

TEST_F(transGroup, functorInt) {
    Accumulate<int> a(0);
    vector<int> out(in.size());
    transform(in.begin(), in.end(), out.begin(), a);
    EXPECT_EQ(out, vector<int>({1, 3, 6}));
}

TEST_F(transGroup, functorFloat) {
    Accumulate<float> a(0.1f);
    vector<float> out(in.size());
    transform(in.begin(), in.end(), out.begin(), a);
    EXPECT_EQ(out, vector<float>({1.1, 3.1, 6.1}));
}

TEST_F(transGroup, lambda) {
    vector<int> out(in.size());
    transform(in.begin(), in.end(), out.begin(),
              [](const int& x) { return x * 2; });
    EXPECT_EQ(out, vector<int>({2, 4, 6}));
}

TEST_F(transGroup, stringToUpper) {
    string o(s.size(), ' ');
    transform(s.begin(), s.end(), o.begin(), ::toupper);
    EXPECT_EQ(o, "RANDOM TEXT");
}

TEST_F(transGroup, stringToLower) {
    string o(s.size(), ' ');
    transform(s.begin(), s.end(), o.begin(), ::tolower);
    EXPECT_EQ(o, "random text");
}

char flipCase(char c) {
    const bool isLowerCase = (('a' <= c) && (c <= 'z'));
    const bool isUpperCase = (('A' <= c) && (c <= 'Z'));
    const char convFactor = ('a' - 'A');

    if (isLowerCase)
        return c - convFactor;
    else if (isUpperCase)
        return c + convFactor;
    return c;
}

TEST_F(transGroup, stringFlipCase) {
    string o(s.size(), ' ');
    transform(s.begin(), s.end(), o.begin(), flipCase);
    EXPECT_EQ(o, "Random Text");
}

TEST_F(transGroup, binaryTransform) {
    vector<int> in2 = {3, 2, 1};
    vector<int> out(in.size(), 0);
    transform(in.begin(), in.end(), in2.begin(), out.begin(),
              [](const int& a, const int& b) { return a + b; });
    EXPECT_EQ(out, vector<int>({4, 4, 4}));
}

string toWords(int in) {
    switch (in) {
        case 1:
            return "one";
        case 2:
            return "two";
        case 3:
            return "three";
        default:
            return "unkown";
    }
}

TEST_F(transGroup, intToString) {
    vector<string> out(in.size(), "");
    transform(in.begin(), in.end(), out.begin(), toWords);
    EXPECT_EQ(out, vector<string>({"one", "two", "three"}));
}
