#include <iostream>
#include <string>

// Component
class Coffee {
public:
    virtual std::string getDescription() = 0;
    virtual double getCost() = 0;
};

// Concrete Component
class SimpleCoffee : public Coffee {
public:
    std::string getDescription() override {
        return "Simple coffee";
    }

    double getCost() override {
        return 1.0;
    }
};

// Decorator
class CoffeeDecorator : public Coffee {
protected:
    Coffee* coffee;

public:
    CoffeeDecorator(Coffee* coffee) : coffee(coffee) {}

    std::string getDescription() override {
        return coffee->getDescription();
    }

    double getCost() override {
        return coffee->getCost();
    }
};

// Concrete Decorators
class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(Coffee* coffee) : CoffeeDecorator(coffee) {}

    std::string getDescription() override {
        return coffee->getDescription() + ", milk";
    }

    double getCost() override {
        return coffee->getCost() + 0.5;
    }
};

class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(Coffee* coffee) : CoffeeDecorator(coffee) {}

    std::string getDescription() override {
        return coffee->getDescription() + ", sugar";
    }

    double getCost() override {
        return coffee->getCost() + 0.2;
    }
};

class WhipDecorator : public CoffeeDecorator {
public:
    WhipDecorator(Coffee* coffee) : CoffeeDecorator(coffee) {}

    std::string getDescription() override {
        return coffee->getDescription() + ", whipped cream";
    }

    double getCost() override {
        return coffee->getCost() + 0.7;
    }
};

// Usage
int main() {
    Coffee* coffee = new SimpleCoffee();
    coffee = new MilkDecorator(coffee);
    coffee = new SugarDecorator(coffee);
    coffee = new WhipDecorator(coffee);

    std::cout << coffee->getDescription() << std::endl;  // Output: Simple coffee, milk, sugar, whipped cream
    std::cout << coffee->getCost() << std::endl;  // Output: 2.4

    delete coffee;

    return 0;
}
