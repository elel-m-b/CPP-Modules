#include <iostream>


int main()
{
    std::string     name = "Hassan";
    std::string     &f = name;
    std::string     *ptr;
    ptr = &name;
    f = "Hello";
    *ptr = 'f';
    std::cout << "after: " << name;
}