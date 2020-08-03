#ifndef STATEPATTERN_HPP
#define STATEPATTERN_HPP

#include <statePatternInterfaces.hpp>

class OpenState : public State {
   public:
    DoorStates getDoorState() override {
        return DoorStates::Opening;
    }
    DoorStates handle(GarageRemoteContext* c) override;
};

class CloseState : public State {
   public:
    DoorStates getDoorState() override {
        return DoorStates::Closing;
    }
    DoorStates handle(GarageRemoteContext* c) override;
};

class StoppedState : public State {
   public:
    DoorStates getDoorState() override {
        return DoorStates::Stopped;
    }
    DoorStates handle(GarageRemoteContext* c) override;
};

class GarageRemoteContext {
    State* _state;

   public:
    GarageRemoteContext(Door* doorRef, Button* button)
        : _state(new StoppedState), door(*doorRef), remoteButton(*button) {
    }
    ~GarageRemoteContext() {
        delete _state;
    }

    Door& door;
    Button& remoteButton;

    DoorStates handle();
    void changeState(State* state);
    State& getState() {
        return *_state;
    }
};

#endif