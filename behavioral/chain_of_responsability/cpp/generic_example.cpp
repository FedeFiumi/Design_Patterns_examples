/* The Chain of Responsibility Pattern is a behavioral design pattern that allows
   an object to pass a request along a chain of potential handlers until the request
   is handled or reaches the end of the chain. Each handler in the chain has the ability
   to either handle the request or pass it to the next handler in the chain.
   This pattern decouples the sender of the request from its receivers, giving multiple
   objects the opportunity to handle the request independently.
*/

#include <iostream>

class Handler {
public:
    virtual void setNext(Handler* handler) = 0;
    virtual void handleRequest(int requestCode) = 0;
};

class ConcreteHandler: public Handler {
public:
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

    return 0;
}
