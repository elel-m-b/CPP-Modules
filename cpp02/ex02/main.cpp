#include "Fixed.hpp"
#include <iostream>

int main()
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;      // 0
    std::cout << ++a << std::endl;    // pre-increment
    std::cout << a << std::endl;      // same value
    std::cout << a++ << std::endl;    // post-increment
    std::cout << a << std::endl;      // incremented value
    std::cout << b << std::endl;      // 10.101
    return 0;
}
