#include <gtest/gtest.h>
#include <statePattern.hpp>

// TEST(stateGroup, wholeClickingCycle) {
//     GarageRemote r;
//     EXPECT_EQ(Door::Opening, r.handle());
//     EXPECT_EQ(Door::Stopped, r.handle());
//     EXPECT_EQ(Door::Closing, r.handle());
//     EXPECT_EQ(Door::Stopped, r.handle());
//     EXPECT_EQ(Door::Opening, r.handle());
// }

TEST(stateGroup, openToStop) {
    GarageRemote r;
    EXPECT_EQ(Door::Opening, r.handle());
    EXPECT_EQ(Door::Opening, r.handle());
    r.click();
    EXPECT_EQ(Door::Stopped, r.handle());
    EXPECT_EQ(Door::Stopped, r.handle());
    r.click();
    EXPECT_EQ(Door::Closing, r.handle());
    EXPECT_EQ(Door::Closing, r.handle());
    r.click();
    EXPECT_EQ(Door::Stopped, r.handle());
    EXPECT_EQ(Door::Stopped, r.handle());
    r.click();
    EXPECT_EQ(Door::Opening, r.handle());
    EXPECT_EQ(Door::Opening, r.handle());
}
