# Chain of Responsibility

Allows an object to pass a request along a chain of potential handlers until the request
is handled or reaches the end of the chain. Each handler in the chain has the ability
to either handle the request or pass it to the next handler in the chain. This pattern
decouples the sender of the request from its receivers, giving multiple objects the
opportunity to handle the request independently.

The class diagram is pretty simple, consisting in a ```handler``` interface and many
concrete ```handler``` classes, one per every different "handling" implementation we
want to have. With "handling" implementation is literally what the current handler should
do, amongst the following points:

* perform an operation

* pass the ball (the responsibility) to the next handler

* Mix of the two point above

The following scheme is not following the usual representation. Usually the nextHandler_
member is placed in the Handler class and the concrete classes implements only
the methods. Preferred this way to have Handler as interface.

Another way possible would be implement a BaseConcrete class implementing a base version
of setNext() and handleRequest() plus adding the nextHandler_ member. Then create
BaseConcrete derived classes overriding the methods when a custom one is needed.

```mermaid
  classDiagram
  direction TB

  class Client

  class Handler{
    <<interface>>
    +setNext(Handler* nextHandler)
    +handleRequest()
  }

  class ConcreteHandler{
    -nextHandler : Handler*
    +setNext(Handler* nextHandler)
    +handleRequest()
  }

  class ConcreteHandlerN{
    -nextHandler : Handler*
    +setNext(Handler* nextHandler)
    +handleRequest()
  }

  Client --> Handler
  Handler <|.. ConcreteHandler
  ConcreteHandler o--> Handler : Successor
  Handler <|.. ConcreteHandlerN
  ConcreteHandlerN o--> Handler : Successor

```
