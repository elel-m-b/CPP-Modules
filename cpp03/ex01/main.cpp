#include "ScavTrap.hpp"

int main()
{
    ScavTrap    a("R1");
    a.attack("P1");
    a.takeDamage(20);
    a.takeDamage(100);
    a.attack("P1");
    a.beRepaired(10);
    ScavTrap    b("R2");
    b.beRepaired(1);
    b.takeDamage(1);
}
