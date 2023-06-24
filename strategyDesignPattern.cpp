#include <iostream>

// Abstract base class for the strategy
class Strategy {
public:
    virtual void execute() = 0;
};

// Concrete strategy implementations
class ConcreteStrategyA : public Strategy {
public:
    void execute() override {
        std::cout << "Executing ConcreteStrategyA" << std::endl;
    }
};

class ConcreteStrategyB : public Strategy {
public:
    void execute() override {
        std::cout << "Executing ConcreteStrategyB" << std::endl;
    }
};

// Context class that uses the strategy
class Context {
private:
    Strategy* strategy;

public:
    Context(Strategy* strategy) : strategy(strategy) {}

    void setStrategy(Strategy* strategy) {
        this->strategy = strategy;
    }

    void executeStrategy() {
        strategy->execute();
    }
};

int main() {
    // Create strategies
    ConcreteStrategyA strategyA;
    ConcreteStrategyB strategyB;

    // Create context with the initial strategy
    Context context(&strategyA);

    // Execute the current strategy
    context.executeStrategy();

    // Change the strategy dynamically
    context.setStrategy(&strategyB);

    // Execute the new strategy
    context.executeStrategy();

    return 0;
}
