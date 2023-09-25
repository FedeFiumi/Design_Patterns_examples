/* The State Pattern is a behavioral design pattern that allows an object to alter
   its behavior when its internal state changes. It encapsulates different behaviors
   into separate state objects and delegates the execution of behavior to the current
   state object.
   This pattern promotes loose coupling between the object and its behavior, making it
   easier to add or modify states without impacting the object's code.
*/

#include <iostream>

// Context class that contains a state
class Context;

// Abstract State class
class State {
public:
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
private:
    State* currentState_;

public:
    Context() : currentState_(new StateA()) {}

    void setState(State* state) {
        delete currentState_;
        currentState_ = state;
    }

    void request() {
        currentState_->handle(*this);
    }
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
    Context context;

    context.request();  // Output: State A handled the request.
    context.request();  // Output: State B handled the request.
    context.request();  // Output: State C handled the request.
    context.request();  // Output: State A handled the request.

    return 0;
}
