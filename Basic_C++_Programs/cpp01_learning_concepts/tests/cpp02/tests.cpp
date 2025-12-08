#include <iostream>

// Ad-hoc polymorphism

/*
    Ad-hoc polymorphism happens at compile-time when the same 
    function name works with different argument types
*/

/*
    In C++, this is usually done via function overloading.
*/

/*
class       Test
{
    public:

    void        print(int a);
    void        print(std::string name);
};

void    Test::print(int     a)
{
    std::cout << "integer " << a << std::endl;;
}

void        Test::print(std::string     name)
{
    std::cout << "string " << name << std::endl;
}

int main()
{
    Test    c1;
    c1.print(1);
    c1.print("Hello world");
}
*/

// 2️⃣ Operator Overloading

/*
-What it is
    Allows you to define what operators (+, -, <<, etc.) do for your class
    Makes your objects behave like built-in types
*/

// Why we need it ??

/*
    Cleaner code (instead of add(a,b), you can do a+b)
    Makes classes more intuitive and natural to use
*/