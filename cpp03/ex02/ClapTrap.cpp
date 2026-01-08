#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap Copy Constructor is called\n";
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
}

ClapTrap::ClapTrap(): name(""), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap Default Constructor is called\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap Copy Assignment Operator is called\n";
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destracteur is called\n";
}

ClapTrap::ClapTrap(const std::string& _name) :name(_name), hitPoints(10), energyPoints(10), attackDamage(0) 
{
    std::cout << "ClapTrap " << name << " has been created!\n";
}

void ClapTrap::attack(const std::string& target) 
{
    if (energyPoints <= 0 || hitPoints <= 0) 
    {
        std::cout << "ClapTrap " << name << " has no energy or is dead and cannot attack.\n";
        return;
    }
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!\n";
    energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) 
{
    if (hitPoints <= 0) 
    {
        std::cout << "ClapTrap " << name << " is already dead.\n";
        return; 
    }
    hitPoints -= amount;
    if (hitPoints < 0)
        hitPoints = 0;
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage. " << "Current hitPoints:  " << hitPoints << "\n";
}

void ClapTrap::beRepaired(unsigned int amount) 
{
    if (energyPoints <= 0 || hitPoints <= 0) 
    {
        std::cout << "ClapTrap " << name << " has no energy or is dead and cannot repair.\n";
        return;
    }
    hitPoints += amount;
    energyPoints--;
    std::cout << "ClapTrap " << name << " is repaired by " << amount  << " points. Current HP: " << hitPoints << "\n";
}