#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(const T &x)
{
    std::cout << x << std::endl;
}

template <typename T>
void increment(T &x)
{
    x++;
}

int main()
{
    int numbers[] = {1, 2, 3, 4, 5};

    std::cout << "Original:" << std::endl;
    iter(numbers, 5, print);

    iter(numbers, 5, increment);

    std::cout << "\nAfter increment:" << std::endl;
    iter(numbers, 5, print);

    std::string words[] = {
        "Hello",
        "CPP07",
        "Templates"
    };

    std::cout << "\nStrings:" << std::endl;
    iter(words, 3, print);

    const double values[] = {1.5, 2.5, 3.5};

    std::cout << "\nConst doubles:" << std::endl;
    iter(values, 3, print);

    return 0;
}