#include <gtest/gtest.h>
#include <statePattern.hpp>

class stateGroup : public ::testing::Test {
   protected:
    DummyButton button;
    DummyDoor door;
};

TEST_F(stateGroup, buttonDefault) { EXPECT_FALSE(button.isClicked()); }

TEST_F(stateGroup, shouldBeClickedFor1Cycle) {
    button.click();
    EXPECT_TRUE(button.isClicked());
    EXPECT_FALSE(button.isClicked());
}

TEST_F(stateGroup, doorDefault) { EXPECT_TRUE(door.isClosing()); }

TEST_F(stateGroup, door) {
    door.close();
    EXPECT_TRUE(door.isClosing());
    door.open();
    EXPECT_FALSE(door.isClosing());
}

TEST_F(stateGroup, garageRemoteDefault) {
    GarageRemoteContext context(door, button);

    EXPECT_EQ(DoorStates::Stopped, context.handle());
}

TEST_F(stateGroup, shouldWaitForNextClickForStateChange) {
    GarageRemoteContext context(door, button);
    EXPECT_EQ(DoorStates::Stopped, context.handle());

    context.remoteButton.click();
    EXPECT_EQ(DoorStates::Opening, context.handle());
    EXPECT_EQ(DoorStates::Opening, context.handle());
    EXPECT_EQ(DoorStates::Opening, context.handle());
}

TEST_F(stateGroup, fullCycle) {
    GarageRemoteContext context(door, button);

    context.remoteButton.click();
    EXPECT_EQ(DoorStates::Opening, context.handle());

    context.remoteButton.click();
    EXPECT_EQ(DoorStates::Stopped, context.handle());

    context.remoteButton.click();
    EXPECT_EQ(DoorStates::Closing, context.handle());

    context.remoteButton.click();
    EXPECT_EQ(DoorStates::Stopped, context.handle());
}
