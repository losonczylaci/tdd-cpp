#ifndef STATEPATTERNINTERFACES_HPP
#define STATEPATTERNINTERFACES_HPP

enum class DoorStates { Opening, Closing, Stopped };

class GarageRemoteContext;

class State {
   public:
    virtual ~State() = default;
    virtual DoorStates handle(GarageRemoteContext* c) = 0;
    virtual DoorStates getDoorState() = 0;
};

class Button {
   public:
    virtual ~Button() = default;
    virtual void click() = 0;
    virtual bool isClicked() = 0;
};

class Door {
   public:
    virtual ~Door() = default;
    virtual void open() = 0;
    virtual void close() = 0;
    virtual bool isClosing() = 0;
};

#endif