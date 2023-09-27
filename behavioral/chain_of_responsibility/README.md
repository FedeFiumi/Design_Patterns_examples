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
