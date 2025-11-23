#include <iostream>
#include <string>

// =========================================================
// 1) WHAT IS A NAMESPACE ?
// ---------------------------------------------------------
// A namespace is like a container that groups functions,
// classes, or variables under a unique name.
// It prevents NAME CONFLICTS if two functions share a name.
//
// Example: cas1::add() and cas2::add() have the same name,
// but do NOT conflict because they are in different namespaces.
//
// NAMESPACE IS NOT A CLASS!
// - To access namespace content → use  ::   (scope operator)
// - To access class object content → use  . (dot operator)
// =========================================================

namespace cas1
{
    int add(int a, int b) { return a + b; }
}

namespace cas2
{
    int add(int a, int b) { return a + b; }
}

// =========================================================
// 2) WHAT IS A MEMBER FUNCTION ?
// ---------------------------------------------------------
// A member function is a function INSIDE a class.
// It belongs to the class.
// You access it using an OBJECT:
//
//      Test t;
//      t.function(1, 2);
// =========================================================

class Test
{
public:
    int function(int a, int b)
    {
        return a + b;
    }
};

// =========================================================
// 3) WHAT IS A STREAM ?
// ---------------------------------------------------------
// A stream is a FLOW OF DATA.
//
// std::cout  → output stream (to screen)
// std::cin   → input stream (from keyboard)
//
// operators:
//     <<  insert data into output stream
//     >>  extract data from input stream
//
// Example:
// std::cout << "Hello";
// std::cin >> name;
// =========================================================


int main()
{
    // USING NAMESPACES
    int r1 = cas1::add(1, 1);
    int r2 = cas2::add(2, 2);

    std::cout << "result 1 = " << r1 << "\n";
    std::cout << "result 2 = " << r2 << "\n";

    // USING MEMBER FUNCTION
    Test t;
    std::cout << "member function result = " << t.function(5, 5) << "\n";

    // USING STREAMS
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;

    std::cout << "Your name is: " << name << std::endl;

    return 0;
}
