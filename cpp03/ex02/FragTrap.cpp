#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    name = "";
    energyPoints = 100;
    attackDamage = 30;
    hitPoints = 100;
    std::cout << "FragTrap Default Constructor is called\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap Copy Constructor is called\n";
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap Copy assignment operator called\n";
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destracteur is called\n";
}

FragTrap::FragTrap(const std::string& _name) : ClapTrap(_name)
{
    name = _name;
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " has been created!\n";
}

void FragTrap::attack(const std::string& target) 
{
    if (energyPoints <= 0 || hitPoints <= 0) 
    {
        std::cout << "FragTrap " << name << " has no energy or is dead and cannot attack.\n";
        return;
    }
    std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!\n";
    energyPoints--;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name << " requests a high five! " << std::endl;
}
