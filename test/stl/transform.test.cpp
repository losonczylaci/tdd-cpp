#include <gtest/gtest.h>
#include <algorithm>
#include <vector>

using namespace std;

class transGroup : public ::testing::Test {
   protected:
    vector<int> in = {1, 2, 3};
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
