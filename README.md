# Design patterns examples
Simple examples on how to implement design patterns in various languages

## Structure
Every pattern is categorized in subdirectories, based on:

1) Design pattern category (Creational, Structural, Behavioral)

2) Design pattern name (Factory, State, etc...)

3) Implementation language (C++, Python, Rust)

## Documentation structure
A markdown readme has to be implemented for every pattern, along with eventual
additional description

![tryout diagram](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.githubusercontent.com/FedeFiumi/Design_Patterns_examples/test/uml_github_support/thisuml.puml)

## Another example with Mermaid

### [Class Diagram](https://mermaid-js.github.io/mermaid/#/classDiagram)

```mermaid
classDiagram
    Animal <|-- Duck
    Animal <|-- Fish
    Animal <|-- Zebra
    Animal : +int age
    Animal : +String gender
    Animal: +isMammal()
    Animal: +mate()
    class Duck{
      +String beakColor
      +swim()
      +quack()
    }
    class Fish{
      -int sizeInFeet
      -canEat()
    }
    class Zebra{
      +bool is_wild
      +run()
    }
```
