#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: no arguments" << std::endl;
        return 1;
    }

    PmergeMe pmerge;

    // 1. Parse numbers
    for (int i = 1; i < argc; ++i)
    {
        int number = pmerge.parseNumber(argv[i]);
        pmerge.addNumber(number);
    }

    // 2. Get the vector
    std::vector<int> numbers = pmerge.getVector();

    // 3. Print before sorting
    std::cout << "Before: ";
    for (std::vector<int>::iterator it = numbers.begin();it != numbers.end(); ++it)
        std::cout << *it << " ";

    std::cout << std::endl;

    // 4. Sort using Ford-Johnson
    pmerge.sortVector(numbers);

    // 5. Print after sorting
    std::cout << "After:  ";
    for (std::vector<int>::iterator it = numbers.begin();it != numbers.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    return 0;
}