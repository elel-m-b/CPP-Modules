/*
    Purpose: Avoid name conflicts when two libraries or parts of code have the same function/class names.
*/
#include <iostream>
namespace  first
{
    void    say_hello()
    {
        std::cout << "Hello world" << std::endl;
    }
}
namespace secend
{
    void    say_hello()
    {
        std::cout << "Hello world" << std::endl;
    }
}

int main(int ac, char **av)
{
    first::say_hello();
    secend::say_hello();
    return (0);
}