#include <gtest/gtest.h>
#include <statePattern.hpp>

class stateGroup : public ::testing::Test {
   protected:
    DummyDoor& door;
    DummyButton& button;
    GarageRemoteContext& context;

   public:
    stateGroup()
        : door(*new DummyDoor),
          button(*new DummyButton),
          context(*new GarageRemoteContext(&door, &button)) {
    }

    ~stateGroup() {
        delete &door;
        delete &button;
        delete &context;
    }
};

TEST_F(stateGroup, buttonDefault) {
    EXPECT_FALSE(button.isClicked());
}

TEST_F(stateGroup, shouldBeClickedFor1Cycle) {
    button.click();
    EXPECT_TRUE(button.isClicked());
    EXPECT_FALSE(button.isClicked());
}

TEST_F(stateGroup, doorDefault) {
    EXPECT_TRUE(door.isClosing());
}

TEST_F(stateGroup, door) {
    door.close();
    EXPECT_TRUE(door.isClosing());
    door.open();
    EXPECT_FALSE(door.isClosing());
}

TEST_F(stateGroup, garageRemoteDefault) {
    EXPECT_EQ(DoorStates::Stopped, context.handle());
    EXPECT_EQ(DoorStates::Stopped, context.handle());
}

TEST_F(stateGroup, shouldWaitForNextClickForStateChange) {
    context.remoteButton.click();
    EXPECT_EQ(DoorStates::Opening, context.handle());
    EXPECT_EQ(DoorStates::Opening, context.handle());

    context.remoteButton.click();
    EXPECT_EQ(DoorStates::Stopped, context.handle());
}

TEST_F(stateGroup, fullOpenCloseCycle) {
    context.remoteButton.click();
    EXPECT_EQ(DoorStates::Opening, context.handle());

    context.remoteButton.click();
    EXPECT_EQ(DoorStates::Stopped, context.handle());

    context.remoteButton.click();
    EXPECT_EQ(DoorStates::Closing, context.handle());

    context.remoteButton.click();
    EXPECT_EQ(DoorStates::Stopped, context.handle());
}
