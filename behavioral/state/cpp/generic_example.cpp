#include <iostream>

// Context class that contains a state
class Context;

// Abstract State class
class State {
public:
    virtual ~State() { std::cout << "Deleting state" << std::endl; }
    virtual void handle(Context& context) = 0;
};

// Concrete State classes
class StateA : public State {
public:
    void handle(Context& context) override;
};

class StateB : public State {
public:
    void handle(Context& context) override;
};

class StateC : public State {
public:
    void handle(Context& context) override;
};

// Context class
class Context {
public:
    Context() : currentState_(new StateA()) {}

    void setState(State* state) {
        delete currentState_;
        currentState_ = state;
    }

    void request() {
        currentState_->handle(*this);
    }

private:
    State* currentState_;
};

// Concrete State A implementation
void StateA::handle(Context& context) {
    std::cout << "State A handled the request." << std::endl;
    context.setState(new StateB());
}

// Concrete State B implementation
void StateB::handle(Context& context) {
    std::cout << "State B handled the request." << std::endl;
    context.setState(new StateC());
}

// Concrete State C implementation
void StateC::handle(Context& context) {
    std::cout << "State C handled the request." << std::endl;
    context.setState(new StateA());
}

// Client code
int main() {
    std::cout << "---- STATE EXAMPLE ----" << std::endl;
    Context context;

    context.request();  // Output: State A handled the request.
    context.request();  // Output: State B handled the request.
    context.request();  // Output: State C handled the request.
    context.request();  // Output: State A handled the request.

    std::cout << std::endl;
    return 0;
}
