#include "PmergeMe.hpp"

template <typename Container>
void printContainer(const Container& container)
{
    for (typename Container::const_iterator it = container.begin();it != container.end();++it){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int PmergeMe::parseNumber(const std::string& str){
    if (str.empty())
        throw std::runtime_error("Invalid number");
    for (size_t i = 0; i < str.length(); i++){
        if (!std::isdigit(str[i]))
            throw std::runtime_error("Invalid number");
    }
    long number = std::strtol(str.c_str(), NULL, 10);
    if (number > INT_MAX)
        throw std::runtime_error("Number too large");
    return static_cast<int>(number);
}

int main(int ac, char **av)
{
    PmergeMe m;

    for (int i = 1; i < ac; i++)
    {
        int number = m.parseNumber(av[i]);
        m.addNumber(number);
    }

    std::cout << "Before: ";
    printContainer(m.getVector());
    m.createVectorPairs();
    return 0;
}