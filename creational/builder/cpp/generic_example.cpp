#include <iostream>
#include <string>
#include <vector>

class Product {
public:
    void set_property_a(const std::string& property_a) {property_a_ = property_a;}
    void set_property_b(const std::string& property_b) {property_b_ = property_b;}
    void add_element_to_property_c(const std::string& property_c) {
        property_c_.push_back(property_c);
    }
    void print_product(void) const {
        std::cout << "product:\npropA: " << property_a_ << "\npropB: " << property_b_ << "\npropC: ";
        for (const auto& element : property_c_) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

private:
    std::string property_a_;
    std::string property_b_;
    std::vector<std::string> property_c_;
};

class Builder {
public:
    virtual ~Builder() = default;
    virtual void buildPropertyA() = 0;
    virtual void buildPropertyB() = 0;
    virtual void buildPropertyC() = 0;
    Product* GetProduct() {return product_;}
    void CreateANewProduct() {product_ = new Product();}

protected:
    Product* product_;
};

class ConcreteBuilder1 : public Builder {
public:
    void buildPropertyA() override {
        product_->set_property_a("A_1");
    }
    void buildPropertyB() override {
        product_->set_property_b("B_1");
    }
    void buildPropertyC() override {
        product_->add_element_to_property_c("C_1_elem_x");
        product_->add_element_to_property_c("C_1_elem_y");
        product_->add_element_to_property_c("C_1_elem_z");
    }
};

class ConcreteBuilder2 : public Builder {
public:
    void buildPropertyA() override {
        product_->set_property_a("A_2");
    }
    void buildPropertyB() override {
        product_->set_property_b("B_2");
    }
    void buildPropertyC() override {
        product_->add_element_to_property_c("C_2_elem_a");
        product_->add_element_to_property_c("C_2_elem_b");
    }
};

class Director {
public:
    void constructProduct(Builder* builder) {builder_ = builder;}
    Product* getProduct() {
        builder_->CreateANewProduct();
        builder_->buildPropertyA();
        builder_->buildPropertyB();
        builder_->buildPropertyC();
        return builder_->GetProduct();
    }

private:
    Builder* builder_;
};

int main () {
    std::cout << "---- BUILDER EXAMPLE ----" << std::endl;
    Director my_director;

    ConcreteBuilder1 my_concrete_product_1;
    my_director.constructProduct(&my_concrete_product_1);
    Product* my_product_1 = my_director.getProduct();

    ConcreteBuilder2 my_concrete_product_2;
    my_director.constructProduct(&my_concrete_product_2);
    Product* my_product_2 = my_director.getProduct();

    my_product_1->print_product();
    my_product_2->print_product();

    delete my_product_1;
    delete my_product_2;

    std::cout << std::endl;

    return 0;
}
