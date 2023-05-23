#include <iostream>
#include <string>
#include <unordered_map>

// Prototype interface
class Animal {
public:
    virtual Animal* clone() = 0;
    virtual void sound() = 0;
    virtual ~Animal() {}
};

// Concrete Prototype 1
class Dog: public Animal {
public:
    Animal* clone() override {
      return new Dog(*this);
    }

    void sound() override {
      std::cout << "CANEEEEE!" << std::endl;
    }
};

// Concrete Prototype 2
class Cat: public Animal {
public:
    Animal* clone() override {
      return new Cat(*this);
    }

    void sound() override {
      std::cout << "MIAOOO!" << std::endl;
    }
};

// Prototype Factory
class AnimalPrototypeFactory {
public:
    AnimalPrototypeFactory() {
      prototypes_["dog"] = new Dog();
      prototypes_["cat"] = new Cat(); 
    }

    Animal* createAnimal(std::string type) const {
      return prototypes_.at(type)->clone();
    }

    ~AnimalPrototypeFactory() {
      for(auto p : prototypes_) {
        delete p.second;
      }
    }

private:
    std::unordered_map<std::string, Animal*> prototypes_;
};

int main() {
  AnimalPrototypeFactory factory;
  Animal* dog1 = factory.createAnimal("dog");
  Animal* cat1 = factory.createAnimal("cat");
  Animal* dog2 = factory.createAnimal("dog");
  Animal* cat2 = factory.createAnimal("cat");

  dog1->sound();
  cat1->sound();
  dog2->sound();
  cat2->sound();

  // Clean up
  delete dog1;
  delete cat1;
  delete dog2;
  delete cat2;
  system("pause");
}