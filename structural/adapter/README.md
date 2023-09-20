# Adapter
Interface that makes two different element that cannot naturally interact due to some
inconsistencies.

## Real life practical example

Typically the brighter example is the electricity plug adapter. It permits to make your
devices with EU plug to work with non EU plugs.

## When it is usually necessary?

In general we opt for that if one of the part of the software to connect cannot be
changed.

* __Legacy code__: adapters are usually implemented to keep the legacy code working while
  proceeding in the refactoring.

* __Multiple classes with different API__: we need to bring in some third party software
  and we need to adapt to the API which are not originally built for our system, or just\
  adapt many classes to look the same to be re-used by the same part of our code.

## UML generic design
