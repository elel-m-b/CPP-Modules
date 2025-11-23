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

class Test
{
private:
    // Encapsulation: data is hidden and accessed through methods
    int a;

public:
    // Getter (read access)
    int getA() const {
        return a;
    }

    // Setter (write access)
    void setA(int value) {
        this->a = value;
    }
};

int main() {
    Test c1;       // Create an object (instance)
    c1.setA(10);   // Set the value
    std::cout << c1.getA() << std::endl;  // Print value
}
