#include <iostream>
#include "Fixed.hpp"

int main() 
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << "value of a == " << a << std::endl;
    std::cout << "value of ++a == " << ++a << std::endl;
    std::cout << "value of a == " << a << std::endl;
    std::cout << "value of a++ == " << a++ << std::endl;
    std::cout << "value of a == " << a << std::endl;
    std::cout << "value of b == " << b << std::endl;
    std::cout << "value of max == " << Fixed::max(a, b) << std::endl;

    return 0;
}
