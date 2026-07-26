#include "functions.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    std::srand(std::time(NULL));

    for (int i = 0; i < 10; i++)
    {
        Base *obj = generate();

        std::cout << "identify(pointer): ";
        identify(obj);

        std::cout << "identify(reference): ";
        identify(*obj);

        std::cout << "------------------------" << std::endl;

        delete obj;
    }

    return 0;
}