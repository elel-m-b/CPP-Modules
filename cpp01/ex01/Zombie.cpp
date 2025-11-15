#include "Zombie.hpp"

Zombie::Zombie()
{};
Zombie::~Zombie()
{
    std::cout << name << ": destroyed" << std::endl;
}

void    Zombie::setName(std::string n)
{
    name = n;
}