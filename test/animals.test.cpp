#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <animals.hpp>
#include <string>

class DogMock : public Dog {
   public:
    DogMock(const std::string& name) : Dog(name) {}
    MOCK_CONST_METHOD0(saySomething, void());
};

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

TEST_F(AnimalsGroup, saySomething) {
    const DogMock d("Bloki");
    EXPECT_CALL(d, saySomething());
    d.saySomething();
}
