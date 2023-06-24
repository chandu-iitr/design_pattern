//  I have a vehicle Class, which have multiple subClass 
//  But 2 of them have same drive proptery that is not available in the base Class
//  Write the Strtegy Design Pattern for this problem.

#include <iostream>

// Abstract base class for the drive strategy
class DriveStrategy {
public:
    virtual void drive() = 0;
};

// Concrete drive strategy implementations
class DriveStrategyCar : public DriveStrategy {
public:
    void drive() override {
        std::cout << "Car Drive Strategy." << std::endl;
    }
};

class DriveStrategyMotorcycle : public DriveStrategy {
public:
    void drive() override {
        std::cout << "MoterCycle Drive Strategy" << std::endl;
    }
};

class DriveStrategySpecialVehicle : public DriveStrategy {
public:
    void drive() override {
        std::cout << "Special Vehical Drive Strategy." << std::endl;
    }
};

// Vehicle base class
class Vehicle{
    private: 
    DriveStrategy* driveStrategy;

    public:
    Vehicle(DriveStrategy *driveStrategy){
        this->driveStrategy = driveStrategy;
    }

    void drive(){
        driveStrategy->drive();
    } 
};

// Car Vehicle subclass with a different drive strategy
class Car : public Vehicle {
    public:
    Car():Vehicle(new DriveStrategyCar()){} 
};

// MoterCycle Vehicle subclass with a different drive strategy
class MoterCycle : public Vehicle {
    private:
    int speed;

    public:
    MoterCycle(int speed):Vehicle(new DriveStrategyMotorcycle()), speed(speed){} 

    void printSpeed(){
        std::cout << "speed of the moterCycle is 20" << std::endl;
    }
};

// Special Vehicle subclass with a different drive strategy
class SpecialVehicle : public Vehicle {
    public:
    SpecialVehicle():Vehicle(new DriveStrategySpecialVehicle()){} 
};


int main() {

    // Create a car with the car drive strategy
    Car car;
    car.drive();
    
    // Create a MoterCycle with the MoterCycle drive strategy
    MoterCycle moterCycle(20);
    moterCycle.drive();
    MoterCycle.printSpeed();

    // create a special Vehicle with special drive strategy
    SpecialVehicle specialVehicle;
    specialVehicle.drive();
    
    return 0;
}
