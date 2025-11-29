#include <iostream>

/*
In C++, a constructor is a special member function used to initialize objects. 
You can have multiple constructors (constructor overloading), such as:

1 - Default constructor – takes no arguments.

2 - Parameterized constructor – takes arguments to initialize the object
*/
// class Point {
//     int x, y;
// public:
//     Point() : x(0), y(0) {}         // default constructor
//     Point(int a, int b) : x(a), y(b) {}  // constructor with arguments
//     void        print(int a);
//     ~Point()
//     {
//         std ::cout << "Destractur is called\n";
//     }
// };

// int main()
// {
//     // Point obj(1, 2);
//     Point obj;
// }

class Point {
    int x, y;
public:
    Point(int a, int b) : x(a), y(b) {   // constructor
        std::cout << "Constructor called\n";
    }

    ~Point() {   // destructor
        std::cout << "Destructor called\n";
    }

    void print() {
        std::cout << x << ", " << y << std::endl;
    }
};

int main() {
    Point p(3, 5);   // constructor runs
    p.print();
}   // destructor runs automatically here, when p goes out of scope
