#include <iostream>
#include <string>
#include <vector>

class Pizza {
public:
    void setCrust(const std::string& crust) { crust_ = crust; }
    void setSauce(const std::string& sauce) { sauce_ = sauce; }
    void addTopping(const std::string& topping) { toppings_.push_back(topping); }
    void printPizza() const {
        std::cout << "Pizza with " << crust_ << " crust, " << sauce_ << " sauce, and toppings: ";
        for (const auto& topping : toppings_) {
            std::cout << topping << ", ";
        }
        std::cout << std::endl;
    }
private:
    std::string crust_;
    std::string sauce_;
    std::vector<std::string> toppings_;
};

class PizzaBuilder {
public:
    virtual ~PizzaBuilder() = default;
    virtual void buildCrust() = 0;
    virtual void buildSauce() = 0;
    virtual void buildToppings() = 0;
    Pizza* getPizza() { return pizza_; }
    void createNewPizza() { pizza_ = new Pizza(); }
protected:
    Pizza* pizza_;
};

class HawaiianPizzaBuilder : public PizzaBuilder {
public:
    void buildCrust() override { pizza_->setCrust("regular"); }
    void buildSauce() override { pizza_->setSauce("tomato"); }
    void buildToppings() override {
        pizza_->addTopping("ham");
        pizza_->addTopping("pineapple");
    }
};

class SpicyPizzaBuilder : public PizzaBuilder {
public:
    void buildCrust() override { pizza_->setCrust("thin"); }
    void buildSauce() override { pizza_->setSauce("spicy"); }
    void buildToppings() override {
        pizza_->addTopping("pepperoni");
        pizza_->addTopping("jalapenos");
    }
};

class Waiter {
public:
    void setPizzaBuilder(PizzaBuilder* builder) { pizzaBuilder_ = builder; }
    Pizza* getPizza() {
        pizzaBuilder_->createNewPizza();
        pizzaBuilder_->buildCrust();
        pizzaBuilder_->buildSauce();
        pizzaBuilder_->buildToppings();
        return pizzaBuilder_->getPizza();
    }
private:
    PizzaBuilder* pizzaBuilder_;
};

int main() {
    Waiter waiter;

    HawaiianPizzaBuilder hawaiianBuilder;
    waiter.setPizzaBuilder(&hawaiianBuilder);
    Pizza* hawaiianPizza = waiter.getPizza();
    hawaiianPizza->printPizza();

    SpicyPizzaBuilder spicyBuilder;
    waiter.setPizzaBuilder(&spicyBuilder);
    Pizza* spicyPizza = waiter.getPizza();
    spicyPizza->printPizza();

    delete hawaiianPizza;
    delete spicyPizza;

    std::cout << "PRESS ENTER:";
    std::cin.get();
    return 0;
}