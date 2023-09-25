# SOLID

The acronym represent a set of principles in order to build clean code.
Rispectively:

* S: Single responsability

* O: Open/closed principle

* L: Liskov substitution

* I: Interface segregation

* D: dependency inversion

## Single responsability

This principle says that every object should be implmented to care/cover only
about a single functionality.

* Example: the class "vehicle" (below) is violating the single responsability principle.
Why? The vehicle should perform only the basic operation we expect from it. Hence the
method ```get_tyre_pressure()``` should not belong to the class, but more in general to
another that is ideally the univocal responsible for it (in the ```Tyre``` class..).

```mermaid
---
title: Single responsability violation
---
  classDiagram
    direction LR
    class Vehicle{
      -tyres
      -chassis
      +steer()
      +move()
      +get_tyre_pressure()
    }

    class Tyre{
    }

    class Chassis{
    }

    Vehicle --o Tyre
    Vehicle --o Chassis
```

```mermaid
---
title: Single responsability complaint example
---
  classDiagram
    direction LR
    class Vehicle{
      -tyres
      -chassis
      +steer()
      +move()
    }

    class Tyre{
      - tyre_pressure
      +get_tyre_pressure()
    }

    class Chassis{
    }

    Vehicle --o Tyre
    Vehicle --o Chassis
```

## Open/closed principle

Open/closed principle says that object entities (classes, modules, functions) should be
open for extensions and closed for modifications. It should be possible to add new
functionalities to a class without modifying its existing code.

* Example: the code below violates the open close principle. Why? Calculating the area
that way oblige to update the function everytime we have to add a shape (e.g. what
happens if i need to add a Circle??).

```c++
#include <iostream>

class Rectangle {
public:
    Rectangle(double width, double height) : width_(width), height_(height) {}

    double getWidth() const { return width_; }
    double getHeight() const { return height_; }

private:
    double width_;
    double height_;
};

class AreaCalculator {
public:
    double calculateArea(const Rectangle& shape) {
      return shape.getWidth() * shape.getHeight();
    }
};

// Usage
void printArea() {
    const Rectangle rect(3.0, 2.0);
    AreaCalculator area_calc;
    std::cout << "Area: " << area_calc.calculateArea(rect) << std::endl;
}
```

What is the solution then?  Instead of modifying the existing class each time we
add a new shape, we can leverage inheritance and polymorphism to achieve the
open-closed principle.

```c++
#include <iostream>

class Shape {
public:
    virtual double calculateArea() const = 0;
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height) : width_(width), height_(height) {}

    double getWidth() const { return width_; }
    double getHeight() const { return height_; }

    double calculateArea() const override {
        return width_ * height_;
    }

private:
    double width_;
    double height_;
};

class Circle : public Shape {
public:
    Circle(double radius) : radius_(radius) {}

    double calculateArea() const override {
        return PI * radius_ * radius_;
    }

private:
    double radius_;
};

// Usage
void printArea(const Shape& shape) {
    std::cout << "Area: " << shape.calculateArea() << std::endl;
}

```

## Liskov substitution

This principle requires subclasses to not only satisfy the syntactic expectations but\
also the behavioral ones, of its parents. To view things from a different perspective,
as a user of a class, I should be able to utilize any of its children that may be passed
to me without caring about which particular child I am calling. This means we have to
ensure that the arguments as well as all the return values of the children are consistent.

__Important: this is not only related to matching the method syntactics (return values,
etc) but also to the functional semantic! (e.g. if a base class returns a float value
between -20 and 20 but the base class returns a value between 33 and 142 then this is
also a violation).__

* Example: in this case the provided abstract method fly is violating the Liskov
substitution since the penguins cannot fly. This violation can lead to unexpected behavior
when code expects a generic Bird to be able to fly but instead gets a swimming penguin.

```c++
#include <iostream>

class Bird {
public:
    virtual void fly() {
        std::cout << "A bird is flying." << std::endl;
    }
};

class Penguin : public Bird {
public:
    void fly() override {
        std::cout << "A penguin is either walking, sliding or swimming, not flying!"
        << std::endl;
    }
};

void makeBirdFly(Bird& bird) {
    bird.fly();
}

int main() {
    Bird bird;
    Penguin penguin;

    makeBirdFly(bird);     // Output: A bird is flying.
    makeBirdFly(penguin);  // Output: A penguin is either walking, sliding or swimming, not flying!

    return 0;
}
```

In practice, you will see the violation of this principle manifesting itself either
in bugs or calls to methods that reveal information about the child specializing the
interface. To fix the code above, it is just necessary to adjust the interface, by
making it more generic and/or make sure it might fit for every subclass. In this case
it is simply enough to opt for ```move()``` instead of ```fly()```. Every bird moves!

```c++
#include <iostream>

class Bird {
public:
    virtual void move() {
        std::cout << "A bird is moving." << std::endl;
    }
};

class Penguin : public Bird {
public:
    void move() override {
        std::cout << "A penguin moves by walking, sliding or swimming!" << std::endl;
    }
};

void makeBirdMove(Bird& bird) {
    bird.move();
}

int main() {
    Bird bird;
    Penguin penguin;

    makeBirdMove(bird);     // Output: A bird is moving.
    makeBirdMove(penguin);  // Output: A penguin moves by walking, sliding or swimming!

    return 0;
}
```

## Interface segregation

__No client should be forced to depend on methods it does not use__. This principle
advocates for the creation of small and atomic interfaces.
Specifically, it is better to have many single-purpose interfaces, than a single (or few)
multi-purpose ones.
This enables our software to be more reusable and customizable since we don’t have
to rely upon or implement functionality we don’t use.

* Example: the following example shows why should keep the interfaces at minimum.
The interface should care about the methods to be used by a vehicle. While the methods
```start()```, ```stop()``` are pretty generic, the methods ```refuel()``` and
```recharge``` not. The latter two should be implemented only on specific vehicles.

```c++
#include <iostream>

class Vehicle {
public:
  virtual void start() = 0;
  virtual void stop() = 0;
  virtual void refuel() = 0;
  virtual void recharge() = 0;
};

class IceVehicle: public Vehicle {
public:
  void start() override {
    std::cout << "Starting the ICE vehicle!" << std::endl;
  }

  void stop() override {
    std::cout << "Stopping the ICE vehicle!" << std::endl;
  }

  void refuel() override {
    std::cout << "Refueling the ICE vehicle!" << std::endl;
  }

  void recharge() override {
    std::cout << "ICE vehicle does not have a traction battery, hence no recharging."
      << std::endl;
  }
};

class ElectricVehicle: public Vehicle {
public:
  void start() override {
    std::cout << "Starting the electric vehicle!" << std::endl;
  }

  void stop() override {
    std::cout << "Stopping the electric vehicle!" << std::endl;
  }

  void refuel() override {
    std::cout << "Electric vehicle does not have a liquid fuel tank, hence no refueling!"
      << std::endl;
  }

  void recharge() override {
    std::cout << "Recharging the electric vehicle!" << std::endl;
  }
};

```

The larger the interface gets, the less maintainable and reusable it becomes.
In order to fix it, this might be the solution:

```c++
#include <iostream>

class EnginePoweredVehicle {
public:
  virtual void start() = 0;
  virtual void stop() = 0;
};

class FuelPoweredVehicle {
public:
  virtual void refuel() = 0;
};

class ElectricPoweredVehicle {
public:
  virtual void recharge() = 0;
};

class ICEVehicle: public EnginePoweredVehicle, public FuelPoweredVehicle {
public:
  void start() override {
    std::cout << "Starting the ICE vehicle!" << std::endl;
  }

  void stop() override {
    std::cout << "Stopping the ICE vehicle!" << std::endl;
  }

  void refuel() override {
    std::cout << "Refueling the ICE vehicle!" << std::endl;
  }
};

class ElectriVehicle: public EnginePoweredVehicle, public ElectricPoweredVehicle {
  void start() override {
    std::cout << "Starting the electric vehicle!" << std::endl;
  }

  void stop() override {
    std::cout << "Stopping the electric vehicle!" << std::endl;
  }

  void recharge() override {
    std::cout << "Recharging the electric vehicle!" << std::endl;
  }
};

```

## Dependency inversion

* __High-level modules should not depend on low-level modules. Both should depend on
  abstractions (e.g. interfaces).__
* __Abstractions should not depend on details. Details (concrete implementations) should
  depend on abstractions.__

This problem is very common also in the embedded world. YOu want to decauple from the low
level, by inverting the dependency. If the high level module is dependent by the low level
one, it is hell to update the code, since a modification on the lower level might cause
a cascade impact on all the upper modules.
Changing the direction of the dependency from the lower level implementation to the higher
makes it incredibly easy to enhance maintainability and modularity.

* Example: for a video game. we have to implement a class named Player. The class has a
method named ```interact_with()```, which makes the player interact with different
objects (the object in the videogame might be a switch, a fan, a door, etc..).

Implementation that violates the principle (Player is dependent by the lower level
implementation...in this case only by switch):

```c++
#include <iostream>

class Switch {
public:
  void interact() {
    switch_state_ = switch_state_ == true ? false : true;
    if (this->switch_state_ == true) {
      std::cout << "Switch is on!" << std::endl;
    } else {
      std::cout << "Switch is off!" << std::endl;
    }
  }

private:
  bool switch_state_ = false;
};

class Player{
public:
  Player() {}
  void interact_with() {
      switch_.interact();
  }

private:
  Switch switch_; //Here it is the dependency!
};

```

But if the objects to interact with become more than one? Here is the correct solution
that invert the dependency to a common lower level interface. The interface then will
the implement a different set of interactions.

```c++
#include <iostream>

class InteractiveObj {
public:
  virtual void interact() = 0;
  virtual ~InteractiveObj() = default;
};

class Switch: public InteractiveObj {
public:
  void interact() {
    std::cout << "Interacted with a switch" << std::endl;
  }
};

class Door: public InteractiveObj {
public:
  void interact() {
    std::cout << "Interacted with a door" << std::endl;
  }
};

class Player {
public:
  Player() {}
  void interact_with(InteractiveObj *obj) {
    if (obj) {
      obj->interact();
    }
  }
};

```
