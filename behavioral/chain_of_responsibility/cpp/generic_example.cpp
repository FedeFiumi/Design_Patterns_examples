#include <iostream>

class Handler {
public:
    virtual ~Handler() { std::cout << "Deleting Handler" << std::endl; }
    virtual void setNext(Handler* handler) = 0;
    virtual void handleRequest(int requestCode) = 0;
};

class ConcreteHandler: public Handler {
public:
    ~ConcreteHandler() { std::cout << "Deleting ConcreteHandler" << std::endl; }

    void setNext(Handler* handler) override {
        delete nextHandler_;
        nextHandler_ = handler;
    }

    void handleRequest(int requestCode) override {
        if ((requestCode > 0) && (requestCode < 10)) {
            std::cout << "Request " << requestCode << " handled." << std::endl;
        } else if (nextHandler_ != nullptr) {
            std::cout << "Passed to handle at: " << this << std::endl;
            nextHandler_->handleRequest(requestCode);
        } else {
            std::cout << "Request " << requestCode << " can't be handled." << std::endl;
        }
    }

private:
    Handler* nextHandler_;
};

// Client code
int main() {
    std::cout << "---- CHAIN OF RESPONSIBILITY EXAMPLE----" << std::endl;

    Handler* handler1 = new ConcreteHandler();
    Handler* handler2 = new ConcreteHandler();
    Handler* handler3 = new ConcreteHandler();

    handler1->setNext(handler2);
    handler2->setNext(handler3);

    // Handled
    handler1->handleRequest(3);
    // Not Handled
    handler1->handleRequest(0);
    // Not Handled
    handler1->handleRequest(100);

    // Clean up
    delete handler1;
    delete handler2;
    delete handler3;

    std::cout << std::endl;
    return 0;
}
