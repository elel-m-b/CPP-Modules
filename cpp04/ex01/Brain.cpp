#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constarcteur is called" << std::endl;
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain Copy Constarcteur is called " << "\n";
    *this = other;
}

Brain &Brain::operator=(const Brain &other)
{    
    if (this != &other )
    {
        std::cout << "OK\n";
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destracteur is called " << std::endl;
}