#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap Default Constructor is called\n";
    name = "";
    hitPoints = 100;
    attackDamage = 20;
    energyPoints = 50;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy Constructor is called\n";
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap Copy assignment operator called\n";
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destracteur is called\n";
}

ScavTrap::ScavTrap(const std::string& _name) : ClapTrap(_name)
{
    name = _name;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " has been created!\n";
}

void ScavTrap::attack(const std::string& target) 
{
    if (energyPoints <= 0 || hitPoints <= 0) 
    {
        std::cout << "ScavTrap " << name << " has no energy or is dead and cannot attack.\n";
        return;
    }
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!\n";
    energyPoints--;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in keeper mode. \n";
}
