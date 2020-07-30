#include <statePattern.hpp>

Door OpenState::handle(GarageRemote& gr) {
    if (gr.isRemoteClicked) gr.changeState(new StoppedState);
    gr.isDoorClosing = false;
    gr.isRemoteClicked = false;
    return gr.getState().getDoorState();
}

Door CloseState::handle(GarageRemote& gr) {
    if (gr.isRemoteClicked) gr.changeState(new StoppedState);
    gr.isDoorClosing = true;
    gr.isRemoteClicked = false;
    return gr.getState().getDoorState();
}

Door StoppedState::handle(GarageRemote& gr) {
    if (not gr.isRemoteClicked)
        return Door::Stopped;
    else if (gr.isDoorClosing)
        gr.changeState(new OpenState);
    else
        gr.changeState(new CloseState);
    gr.isRemoteClicked = false;
    return gr.getState().getDoorState();
}

Door GarageRemote::handle() { return _state->handle(*this); }

void GarageRemote::changeState(State* state) {
    delete _state;
    if (state != nullptr) _state = state;
}
