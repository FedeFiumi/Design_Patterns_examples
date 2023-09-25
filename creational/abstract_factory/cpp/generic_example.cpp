#include <iostream>
#include <memory>

/*
In order of hierarchy from top to bottom

1) Abstract Factory:
    (Is the head of production level, that permits the creation of several
     other sub-factories for different concrete products)
     Should be an abstract class calling the creation of the abstract product

2) Concrete Factory:
    (is the place in which the concrete product are produced)

3) Abstract Products:
    (Might be the physical product, like a chair, a bicycle, etc)
    Should be abstract: just the function and destructor

4) Concrete products:
    (Might be the specific type of the product, es: design or plain chair,
     race or mtb bicycle)
    Implements product abstract class

*/

/* Abstract Products */

class Elem1 {
public:
    virtual void do_this() = 0;
    virtual ~Elem1() {}
};

class Elem2 {
public:
    virtual void do_that() = 0;
    virtual ~Elem2() {}
};

/* Concrete Products */

class Elem1Type1 : public Elem1 {
public:
    void do_this() {
        std::cout << "Elem1Type1" << std::endl;
    }
};

class Elem1Type2 : public Elem1 {
public:
    void do_this() {
        std::cout << "Elem1Type2" << std::endl;
    }
};

class Elem2Type1 : public Elem2 {
public:
    void do_that() {
        std::cout << "Elem2Type1" << std::endl;
    }
};

class Elem2Type2 : public Elem2 {
public:
    void do_that() {
        std::cout << "Elem2Type2" << std::endl;
    }
};

/* Concrete Factories */

class AbstrFactory {
public:
    virtual std::unique_ptr<Elem1>createElem1() = 0;
    virtual std::unique_ptr<Elem2>createElem2() = 0;
    virtual ~AbstrFactory() {}
};


/* Concrete Factories */

class ConcreteFactoryType1 : public AbstrFactory {
public:
    std::unique_ptr<Elem1> createElem1() {
#if __cplusplus == 201103L
        return std::unique_ptr<Elem1>(new Elem1Type1());
#else
        return std::make_unique<Elem1Type1>();
#endif
    }

    std::unique_ptr<Elem2> createElem2() {
#if __cplusplus == 201103L
        return std::unique_ptr<Elem2>(new Elem2Type1());
#else
        return std::make_unique<Elem2Type1>();
#endif
    }
};

class ConcreteFactoryType2 : public AbstrFactory {
public:
    std::unique_ptr<Elem1> createElem1() {
#if __cplusplus == 201103L
        return std::unique_ptr<Elem1>(new Elem1Type2());
#else
        return std::make_unique<Elem1Type2>();
#endif
    }

    std::unique_ptr<Elem2> createElem2() {
#if __cplusplus == 201103L
        return std::unique_ptr<Elem2>(new Elem2Type2());
#else
        return std::make_unique<Elem2Type2>();
#endif
    }
};

/* Main function */
int main() {
    std::cout << "---- ABSTRACT FACTORY EXAMPLE----" << std::endl;

    // Define a concrete factory
#if __cplusplus == 201103L
    std::unique_ptr<AbstrFactory> my_type1_factory = std::unique_ptr<AbstrFactory>(new ConcreteFactoryType1());
    std::unique_ptr<AbstrFactory> my_type2_factory = std::unique_ptr<AbstrFactory>(new ConcreteFactoryType1());
#else
    std::unique_ptr<AbstrFactory> my_type1_factory = std::make_unique<ConcreteFactoryType1>();
    std::unique_ptr<AbstrFactory> my_type2_factory = std::make_unique<ConcreteFactoryType2>();
#endif

    // Produce the Type1 products
    std::unique_ptr<Elem1> my_fact1_elem1 = my_type1_factory->createElem1();
    std::unique_ptr<Elem2> my_fact1_elem2 = my_type1_factory->createElem2();

    my_fact1_elem1->do_this();
    my_fact1_elem2->do_that();

    // Produce the Type2 products
    std::unique_ptr<Elem1> my_fact2_elem1 = my_type2_factory->createElem1();
    std::unique_ptr<Elem2> my_fact2_elem2 = my_type2_factory->createElem2();

    my_fact2_elem1->do_this();
    my_fact2_elem2->do_that();

    std::cout << std::endl;

    return 0;
}
