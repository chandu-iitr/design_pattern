#include <iostream>
#include <string>

using namespace std;

// Base Pizza Abstract Class
class BasePizza{
    public:
    virtual string getDescription() = 0;
    virtual double getCost() = 0;
};

// Base Pizza Concrete Class
class Margherita : public BasePizza{
    public:
    string getDescription(){
        return "Margherita Pizza";
    }

    double getCost(){
        return 10.0;
    }
};

class VegDelight : public BasePizza{
    public:
    string getDescription(){
        return "Veg Delight";
    }

    double getCost(){
        return 12.0;
    }
};

// Decorator
class ToppingDecorator : public BasePizza {
    protected : 
    BasePizza* basePizza;

    public :
    ToppingDecorator(BasePizza* basePizza) : basePizza(basePizza) {}
    
    string getDescription(){
        return basePizza->getDescription();
    }

    double getCost(){
        return basePizza->getCost();
    }
};

// Concrete Decorator
class ExtraCheeze : public ToppingDecorator{
    public:
    ExtraCheeze(BasePizza* basePizza) : ToppingDecorator(basePizza) {}

    string getDescription(){
        return basePizza->getDescription() + ", Extra Cheeze ";
    }

    double getCost(){
        return basePizza->getCost() + 1.5 ;
    }
};


class Mushroom : public ToppingDecorator{
    public : 
    Mushroom(BasePizza* basePizza) : ToppingDecorator(basePizza) {}

    string getDescription(){
        return basePizza->getDescription() + ", Mushroom ";
    }

    double getCost(){
        return basePizza->getCost() + 2.5 ;
    }
};

int main(){

    BasePizza* basePizza = new Margherita();
    basePizza = new ExtraCheeze(basePizza);
    basePizza = new Mushroom(basePizza);
    basePizza = new ExtraCheeze(basePizza);

    cout << basePizza->getDescription() << endl;
    cout << basePizza->getCost() << endl;

}


