#include <gtest/gtest.h>
#include <animals.hpp>
#include <string>

class AnimalsGroup : public ::testing::Test {
   protected:
};

TEST_F(AnimalsGroup, dog) {
    Dog d("Bloki");
    ASSERT_EQ("Bloki", d.getName());
    ASSERT_EQ("Bloki", d.getName());
}

TEST_F(AnimalsGroup, dogSound) {
    const Dog d("Bloki");
    ASSERT_EQ("bark-bark", d.getSound());
}
