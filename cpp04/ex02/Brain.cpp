#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called\n";
    for(int i = 0; i < MAX_IDEAS; i++)
        ideas[i] = "someideas";
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain copy constructor called\n";
    for(int i = 0; i < MAX_IDEAS; i++)
        ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Brain Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < MAX_IDEAS; i++)
            ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called\n";
}
