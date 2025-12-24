#include "Fixed.hpp"

int main()
{
    Fixed a(10);
    Fixed b(42.42f);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    return 0;
}
