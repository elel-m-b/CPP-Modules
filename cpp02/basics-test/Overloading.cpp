#include <iostream>

// Ad-hoc Polymorphism (Function Overloading) 
/*
Definition:
    Ad-hoc polymorphism allows you to define multiple functions with the same name but different parameter types or numbers. 
    The compiler chooses the correct version at compile-time.
*/

void        print(int x)
{
    std::cout << "Integer: " << x << std::endl;
}
void    print(double x)
{
    std::cout << "Double: " << x << std::endl;
}
void    print(const std::string &x)
{
    std::cout << "String: " << x << std::endl;
}

int main()
{
    print(42);
    print(3.14);
    print("Hello");
}