# State pattern

This pattern that allows an object to alter its behavior when its internal state changes.
It encapsulates different behaviors into separate state objects and delegates the
execution of behavior to the current state object.
This pattern promotes loose coupling between the object and its behavior, making it easier
to add or modify states without impacting the object's code.

It consists of:

* Context: this is the main considered object, with a changing internal state

* States: derived classes in charge of manage the internal state of the system

In a nutshell, hte context work as a "FSM execution environment":

* Every time a ```request()``` is called, the internal FSM evolves (A state handle is called)

* Every time a ```setState(State *state)``` is called, the state is changed (context update his state)

```mermaid
  classDiagram
  direction LR
    class Context{
      -state : State*
      +setState(State *state)
      +request()
    }

    class State{
      <<interface>>
      -context : Context*
      +handle(Context* context)
    }

    class StateA{
      +handle(Context* context)
    }

    class StateB{
      +handle(Context* context)
    }

    class StateZ{
      +handle(Context* context)
    }

  Context o--> State
  State <|.. StateA
  State <|.. StateB
  State <|.. StateZ

```

Implementation example sequence diagram:

```mermaid
  sequenceDiagram
      Note right of Context: StateA instantiated as starting state
      Context->>StateA: request()
      activate Context
      activate StateA
      StateA-->>Context: setState(new StateB)
      deactivate Context
      deactivate StateA

      Context->>StateB: request()
      activate Context
      activate StateB
      StateB-->>Context: setState(new StateZ)
      deactivate Context
      deactivate StateB

      Context->>StateZ: request()
      activate Context
      activate StateZ
      StateZ-->>Context: setState(new StateA)
      Note right of Context: StateA at the next update..
      deactivate Context
      deactivate StateZ

```
