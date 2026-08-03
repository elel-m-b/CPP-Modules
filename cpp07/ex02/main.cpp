#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
    try
    {
        std::cout << "===== INT ARRAY =====" << std::endl;

        Array<int> numbers(5);

        for (unsigned int i = 0; i < numbers.size(); i++)
            numbers[i] = i * 10;

        for (unsigned int i = 0; i < numbers.size(); i++)
            std::cout << numbers[i] << std::endl;

        std::cout << "\n===== COPY CONSTRUCTOR =====" << std::endl;

        Array<int> copy(numbers);

        copy[0] = 999;

        std::cout << "Original: " << numbers[0] << std::endl;
        std::cout << "Copy:     " << copy[0] << std::endl;

        std::cout << "\n===== ASSIGNMENT =====" << std::endl;

        Array<int> assign;

        assign = numbers;

        assign[1] = 555;

        std::cout << "Original: " << numbers[1] << std::endl;
        std::cout << "Assign:   " << assign[1] << std::endl;

        std::cout << "\n===== STRING ARRAY =====" << std::endl;

        Array<std::string> words(3);

        words[0] = "Hello";
        words[1] = "CPP07";
        words[2] = "Templates";

        for (unsigned int i = 0; i < words.size(); i++)
            std::cout << words[i] << std::endl;

        std::cout << "\n===== EXCEPTION =====" << std::endl;

        std::cout << numbers[100] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return (0);
}