#include <gtest/gtest.h>
#include <statePattern.hpp>

class FakeDoor : public Door {
    bool _isClosing = true;

   public:
    void open() override {
        _isClosing = false;
    }
    void close() override {
        _isClosing = true;
    }
    bool isClosing() override {
        return _isClosing;
    };
};

class FakeButton : public Button {
    bool _isClicked = false;

   public:
    void click() override {
        _isClicked = true;
    }

    bool isClicked() override {
        bool retVal = _isClicked;
        _isClicked = false;
        return retVal;
    }
};

class stateGroup : public ::testing::Test {
   protected:
    FakeDoor& door;
    FakeButton& button;
    GarageRemoteContext& context;

   public:
    stateGroup()
        : door(*new FakeDoor),
          button(*new FakeButton),
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
