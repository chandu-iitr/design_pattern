#include <iostream>
#include <vector>
#include <algorithm>

// Forward declaration of Subject class
class Subject;

// Observer class
class Observer {
public:
    virtual void update() = 0;
};

// Subject class
class Subject {
private:
    std::vector<Observer*> observers;
    int state;

public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void detach(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void setState(int newState) {
        state = newState;
        notify();
    }

    int getState() const {
        return state;
    }

    void notify() {
        for (Observer* observer : observers) {
            observer->update();
        }
    }
};

// Concrete Observer classes
class ConcreteObserverA : public Observer {
private:
    Subject* subject;

public:
    ConcreteObserverA(Subject* subject) : subject(subject) {}

    void update() {
        std::cout << "ConcreteObserverA: Received update. New state is " << subject->getState() << std::endl;
    }
};

class ConcreteObserverB : public Observer {
private:
    Subject* subject;

public:
    ConcreteObserverB(Subject* subject) : subject(subject) {}

    void update() {
        std::cout << "ConcreteObserverB: Received update. New state is " << subject->getState() << std::endl;
    }
};

int main() {
    // Create subject and observers
    Subject subject;
    ConcreteObserverA observerA(&subject);
    ConcreteObserverB observerB(&subject);

    // Attach observers to the subject
    subject.attach(&observerA);
    subject.attach(&observerB);

    // Change the subject's state
    subject.setState(5);

    // Detach observerA
    subject.detach(&observerA);

    // Change the subject's state again
    subject.setState(10);

    return 0;
}
