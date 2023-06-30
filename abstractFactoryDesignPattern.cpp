#include <iostream>
#include <string>

// Abstract Product A
class AbstractProductA {
public:
    virtual void useA() = 0;
};

// Concrete Product A1
class ConcreteProductA1 : public AbstractProductA {
public:
    void useA() override {
        std::cout << "Using ConcreteProductA1" << std::endl;
    }
};

// Concrete Product A2
class ConcreteProductA2 : public AbstractProductA {
public:
    void useA() override {
        std::cout << "Using ConcreteProductA2" << std::endl;
    }
};

// Abstract Product B
class AbstractProductB {
public:
    virtual void useB() = 0;
};

// Concrete Product B1
class ConcreteProductB1 : public AbstractProductB {
public:
    void useB() override {
        std::cout << "Using ConcreteProductB1" << std::endl;
    }
};

// Concrete Product B2
class ConcreteProductB2 : public AbstractProductB {
public:
    void useB() override {
        std::cout << "Using ConcreteProductB2" << std::endl;
    }
};

// Abstract Factory
class AbstractFactory {
public:
    virtual AbstractProductA* createProductA() = 0;
    virtual AbstractProductB* createProductB() = 0;
};

// Concrete Factory 1
class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA1();
    }

    AbstractProductB* createProductB() override {
        return new ConcreteProductB1();
    }
};

// Concrete Factory 2
class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA2();
    }

    AbstractProductB* createProductB() override {
        return new ConcreteProductB2();
    }
};

int main() {
    AbstractFactory* factory1 = new ConcreteFactory1();
    AbstractProductA* productA1 = factory1->createProductA();
    AbstractProductB* productB1 = factory1->createProductB();
    productA1->useA();
    productB1->useB();

    AbstractFactory* factory2 = new ConcreteFactory2();
    AbstractProductA* productA2 = factory2->createProductA();
    AbstractProductB* productB2 = factory2->createProductB();
    productA2->useA();
    productB2->useB();

}