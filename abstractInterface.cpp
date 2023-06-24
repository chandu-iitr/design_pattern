#include <iostream>
using namespace std;

// Abstract base class (equivalent to Java interface)
class AbstractInterface {
public:
    virtual void method() = 0;  // Pure virtual function
};

// First concrete class implementing the abstract interface
class ConcreteClassA : public AbstractInterface {
public:
    void method() override {
        std::cout << "Implementation of method() in ConcreteClassA" << std::endl;
    }
};

// Second concrete class implementing the abstract interface
class ConcreteClassB : public AbstractInterface {
public:
    void method() override {
        std::cout << "Implementation of method() in ConcreteClassB" << std::endl;
    }
};

int main() {
    ConcreteClassB concreteObject;
    concreteObject.method();

    AbstractInterface* abstractObject = &concreteObject;
    abstractObject->method();

    ConcreteClassA concreteObject1;
    concreteObject1.method();

    AbstractInterface* abstractObject1 = &concreteObject1;
    abstractObject1->method();

    return 0;
}
