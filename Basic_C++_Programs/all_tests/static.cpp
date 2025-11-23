#include <iostream>

// Shared among all objects of a class.

class   Counter
{
    public:
    static int count;
    Counter() {count++;}
};
int     Counter::count = 0;
int main()
{
    Counter a, b;
    std::cout << Counter::count;
}