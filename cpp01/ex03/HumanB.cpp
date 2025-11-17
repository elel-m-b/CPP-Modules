#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name) 
{
    this->name = name;
    this->weapon = NULL; // or nullptr
}


HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& weapon) 
{
    this->weapon = &weapon;
}

void HumanB::attack() const 
{
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon to attack with" << std::endl;
}
