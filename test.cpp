// #include<iostream>
// using namespace std;

// class Employee{
//     public:
//     int id;
//     string name;

//     Employee(int id){
//         this->id = id;
//     }
    
//     void displayJob(string job){
//         cout << "Employee : " << job << endl;
//     }

// };

// class Finance : public Employee{
//     public :
//     Finance(int id) : Employee(id) {}

//     void displayJob(string job){
//         cout << " Finance : " << job << endl;
//     }
// };

// int main(){
    
//     Employee E1(2);
//     Finance F1(3);
//     E1.displayJob("asd") ;
//     F1.displayJob("sdsf");
//     return 0;
// }

#include <iostream>
using namespace std;

class Base1 {
public:
    void display() {
        cout << "Base1::display()" << endl;
    }
};

class Base2 {
public:
    void display() {
        cout << "Base2::display()" << endl;
    }
};

class Derived : public Base1, public Base2 {
};

int main() {
    Derived obj;
    obj.Base2::display(); // Ambiguous function call

    return 0;
}
