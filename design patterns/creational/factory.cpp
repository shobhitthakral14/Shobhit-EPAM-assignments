// The Factory Method Design Pattern is a creational design pattern used in software development. 
// It provides an interface for creating objects in a superclass while allowing subclasses to specify the types of objects they create.


// This pattern simplifies the object creation process by placing it in a dedicated method,
// promoting loose coupling between the object creator and the objects themselves.

// This approach enhances flexibility, extensibility, and maintainability, 
// enabling subclasses to implement their own factory methods for creating specific object types.



#include<iostream>


// Step 1: Define the Abstract Product (Shape)

// Abstract product class
class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() {} // Virtual destructor for polymorphism
};
// Here, we've defined an abstract class Shape with a pure virtual function draw().
//  This class represents the abstract product that all concrete products must inherit from.

// Concrete product class - Circle
class Circle : public Shape {
public:
    void draw() override {
        std::cout<<"Drawing a Circle"<< std::endl;
    }
};

// Concrete product class - Square
class Square : public Shape {
public:
    void draw() override {
        std::cout<<"Drawing a Square"<<std::endl;
    }
};

// Here, we have two concrete classes, Circle and Square, that inherits from the Shape abstract class.
// Each concrete product (Circle and Square) provides its implementation of the draw() method.


// Step 3: Define the Abstract Creator

// Abstract creator class
class ShapeFactory {
public:
    virtual Shape* createShape() = 0;
    virtual ~ShapeFactory() {} // Virtual destructor for polymorphism
};

//The abstract creator class, ShapeFactory, declare a pure virtual function createShape(),
// which will be implemented by concrete creators to create specific shapes.



// Step 4: Define Concrete Creators (CircleFactory and Square Factory)
// Concrete creator class - CircleFactory
class CircleFactory : public ShapeFactory {
public:
    Shape* createShape() override {
        return new Circle();
    }
};

// Concrete creator class - SquareFactory
class SquareFactory : public ShapeFactory {
public:
    Shape* createShape() override {
        return new Square();
    }
};

// In this step, we've created two concrete creator classes, CircleFactory and SquareFactory, which implement
//  the createShape() method to create instances of Circle and Square, respectively.

int main() {
    ShapeFactory* circleFactory = new CircleFactory();
    ShapeFactory* squareFactory = new SquareFactory();

    Shape* circle = circleFactory->createShape();
    Shape* square = squareFactory->createShape();

    circle->draw(); // Output: Drawing a Circle
    square->draw(); // Output: Drawing a Square

    delete circleFactory;
    delete squareFactory;
    delete circle;
    delete square;

    return 0;
}

// In this client code, we first create instances of the concrete creators (circleFactory and squareFactory) and then use them to create instances of concrete products (cirlce and square). Finally, we call the draw() method on these objects, which produces the expected output.