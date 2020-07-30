
enum class Door { Opening, Closing, Stopped };

class GarageRemote;

class State {
   public:
    virtual ~State() = default;
    virtual Door handle(GarageRemote&) = 0;
    virtual Door getDoorState() = 0;
};

class OpenState : public State {
   public:
    Door getDoorState() { return Door::Opening; }
    Door handle(GarageRemote&) override;
};

class CloseState : public State {
   public:
    Door getDoorState() { return Door::Closing; }
    Door handle(GarageRemote&) override;
};

class StoppedState : public State {
   public:
    Door getDoorState() { return Door::Stopped; }
    Door handle(GarageRemote&) override;
};

class GarageRemote {
    State* _state;

   public:
    bool isDoorClosing;
    bool isRemoteClicked;
    GarageRemote()
        : _state(new OpenState), isDoorClosing(true), isRemoteClicked(false) {}
    ~GarageRemote() { delete _state; }
    Door handle();
    void changeState(State* state);
    void click() { isRemoteClicked = true; }
    State& getState() { return *_state; }
};
