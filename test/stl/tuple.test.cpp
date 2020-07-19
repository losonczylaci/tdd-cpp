#include <gtest/gtest.h>
#include <cinttypes>
#include <utility>

using namespace std;

class tupleGroup : public ::testing::Test {
   public:
    tuple<int, uint8_t> t = {1, 'a'};
};

TEST_F(tupleGroup, tupleGet) {
    EXPECT_EQ(get<0>(t), 1);
    EXPECT_EQ(get<1>(t), 'a');
}

TEST_F(tupleGroup, tupleTie) {
    int nr;
    uint8_t c;
    tie(nr, c) = t;
    EXPECT_EQ(nr, 1);
    EXPECT_EQ(c, 'a');
}

TEST_F(tupleGroup, tupleIgnore) {
    int nr;
    tie(nr, ignore) = t;
    EXPECT_EQ(nr, 1);
}

TEST_F(tupleGroup, makeTuple) {
    //
    auto mt = make_tuple(1.0f, true);
    EXPECT_FLOAT_EQ(get<0>(mt), 1.0f);
    EXPECT_EQ(get<1>(mt), true);
}

TEST_F(tupleGroup, tupleCat) {
    auto mt = make_tuple(1.0f, true);
    auto ct = tuple_cat(t, mt);
    EXPECT_EQ(ct, make_tuple(1, 'a', 1.0f, true));
}

TEST_F(tupleGroup, tupleCopyCtor) {
    auto tt = t;
    EXPECT_EQ(tt, t);
}
