#include <iostream>

class MyClass 
{
    public:
    void func1() { std::cout << "func1\n"; }
    void func2() { std::cout << "func2\n"; }
    void func3() { std::cout << "func3\n"; }
    void func4() { std::cout << "func4\n"; }
};

void (MyClass::*funcArray[4])() = { &MyClass::func1, &MyClass::func2, &MyClass::func3, &MyClass::func4 };


int main()
{
     MyClass obj;

    // Call all functions in the array
    for (int i = 0; i < 4; ++i) {
        (obj.*funcArray[i])();  // syntax to call member function pointer
    }

}