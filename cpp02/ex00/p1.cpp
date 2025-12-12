#include <iostream>


int main()
{
    float   a = 0.1;
    float b = 0.2;
    float c = a+b;
    std::cout << c;
    if (a + b != 0.3)
        std::cout << "ok\n";
}