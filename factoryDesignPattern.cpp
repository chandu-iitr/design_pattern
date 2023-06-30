#include <iostream>
#include <string>
using namespace std;

// Shape Abstract Class
class Shape {
    public:
    virtual void draw() = 0;
};


// Concrete Class of Shape 
class Rectangle : public Shape{
    public:
    void draw() {
        cout << "Rectangle" << endl;
    }
};

class Circle : public Shape {
    public:
    void draw() {
        cout << "Circle" << endl;
    }
};

// Shape Factory
class ShapeFactory{
    public:
    Shape* getShape(string shape){
        if(shape == "circle")
            return new Circle();
        else if (shape == "rectangle")
            return new Rectangle();
        else
            return NULL;
    }
};


int main(){
    ShapeFactory* shapeFactory = new ShapeFactory();
    Shape* shapeOBJ = shapeFactory->getShape("circle");
    shapeOBJ->draw();
    shapeOBJ = shapeFactory->getShape("rectangle");
    shapeOBJ->draw();
    return 0;
}