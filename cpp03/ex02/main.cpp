#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    FragTrap    a("P1");
    ScavTrap    b("P2");
    a.highFivesGuys();
    a.attack("Hassan");
    a.takeDamage(20);
    a.takeDamage(100);
    a.attack("Hassan");
    b.attack("Hassan");
}