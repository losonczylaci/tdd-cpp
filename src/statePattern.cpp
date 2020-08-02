#include <statePattern.hpp>

DoorStates OpenState::handle(GarageRemoteContext* c) {
    if (c->remoteButton.isClicked()) {
        c->changeState(new StoppedState);
    }
    c->door.open();
    return c->getState().getDoorState();
}

DoorStates CloseState::handle(GarageRemoteContext* c) {
    if (c->remoteButton.isClicked()) {
        c->changeState(new StoppedState);
    }
    c->door.close();
    return c->getState().getDoorState();
}

DoorStates StoppedState::handle(GarageRemoteContext* c) {
    if (not c->remoteButton.isClicked()) {
        return DoorStates::Stopped;
    }
    if (c->door.isClosing()) {
        c->changeState(new OpenState);
    } else {
        c->changeState(new CloseState);
    }
    return c->getState().getDoorState();
}

DoorStates GarageRemoteContext::handle() {
    return _state->handle(this);
}

void GarageRemoteContext::changeState(State* state) {
    delete _state;
    if (state != nullptr) {
        _state = state;
    }
}
