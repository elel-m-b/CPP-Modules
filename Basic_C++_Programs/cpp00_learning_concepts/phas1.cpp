#include <iostream>
// Object-oriented programming (OOP):
// A programming paradigm based on objects that contain data (attributes)
// and functions (methods).

// Class:
// A blueprint/template used to create objects. It does not occupy memory
// until an object (instance) is created.

// Object:
// An instance of a class. It occupies memory and contains the attributes
// and methods defined in the class.



// here are the core OOP concepts:

/*
    Polymorphism
        
    Abstraction
        
    Encapsulation
        
    Object Oriented Programming
        
    Inheritance
        
    Classes
        
    Objects
*/


//  1 - Objects - The Foundation

/*
    Definition: Objects are instances that contain both data and behaviors.
*/

// 2 - Classes - Blueprints for Objects

/*
    Definition: Classes define the structure and behavior that objects will have.
*/

// 3 - Encapsulation

/*
    Data Protection with Getters/Setters
*/

// 4 - Inheritance

/*
    Definition: Inheritance allows a new class to inherit properties and behaviors from an existing class.

    Simple Inheritance
*/

/*
    class Animal 
    {
        public:
        void eat() 
        {
            cout << "Animal is eating" << endl;
        }
    };

    Derived class
    class Cat : public Animal 
    {
        public:
        void meow() 
        {
            cout << "Cat says meow!" << endl;
        }
    };

    int main() 
    {
        Cat myCat;
        myCat.eat();   // Inherited from Animal
        myCat.meow();  // Own method
        
        return 0;
    }
*/

// 5. Polymorphism

/*
    Definition: Polymorphism allows objects of different types to be treated as objects of a common type.
*/

/*
#include <iostream>
using namespace std;

class Shape 
{
    public:
    virtual void draw() {  // Virtual enables polymorphism
        cout << "Drawing shape" << endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing circle" << endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        cout << "Drawing square" << endl;
    }
};

int main() {
    Shape* shape1 = new Circle();
    Shape* shape2 = new Square();
    
    shape1->draw();  // Output: Drawing circle
    shape2->draw();  // Output: Drawing square
    
    delete shape1;
    delete shape2;
    return 0;
}
*/

// 6 - Abstraction

/*
#include <iostream>
using namespace std;

Abstract class
class Vehicle 
{
public:
    virtual void start() = 0;  // Pure virtual function
    
    void stop() {  // Concrete function
        cout << "Vehicle stopped" << endl;
    }
};

class Car : public Vehicle {
public:
    void start() override {
        cout << "Car started with key" << endl;
    }
};

class Bike : public Vehicle {
public:
    void start() override {
        cout << "Bike started with kick" << endl;
    }
};

int main() {
    Car myCar;
    Bike myBike;
    
    myCar.start();   // Output: Car started with key
    myBike.start();  // Output: Bike started with kick
    myCar.stop();    // Output: Vehicle stopped
    
    return 0;
}
*/