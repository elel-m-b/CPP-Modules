#include <iostream>
#include <vector>
#include "Span.hpp"

int main()
{
    std::cout << "===== Basic test =====" << std::endl;
    try{
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e){
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "===== Full Span test =====" << std::endl;
    try{
        Span sp(3);

        sp.addNumber(10);
        sp.addNumber(20);
        sp.addNumber(30);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp.longestSpan() << std::endl;

        // Should throw
        sp.addNumber(40);
    }
    catch (const std::exception& e){
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "===== Not enough numbers test =====" << std::endl;
    try
    {
        Span sp(5);
        sp.addNumber(42);
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "===== Range insertion test =====" << std::endl;
    try
    {
        Span sp(10);

        std::vector<int> numbers;
        numbers.push_back(1);
        numbers.push_back(20);
        numbers.push_back(5);
        numbers.push_back(100);
        numbers.push_back(50);
        sp.addNumber(numbers.begin(), numbers.end());
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "===== 10,000 numbers test =====" << std::endl;
    try
    {
        Span sp(10000);

        for (int i = 0; i < 10000; ++i)
            sp.addNumber(i);

        std::cout << "Number of elements: " << sp.size() << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "===== Range + capacity test =====" << std::endl;
    try
    {
        Span sp(5);
        std::vector<int> numbers;
        numbers.push_back(10);
        numbers.push_back(20);
        numbers.push_back(30);
        numbers.push_back(40);
        numbers.push_back(50);
        numbers.push_back(60);
        // Should throw because 6 numbers won't fit in Span(5)
        sp.addNumber(numbers.begin(), numbers.end());
    }
    catch (const std::exception& e){
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}