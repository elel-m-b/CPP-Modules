#include "ScavTrap.hpp"

int main()
{
    ScavTrap    c1("R1");
    c1.guardGate();
    c1.attack("P1");
    c1.beRepaired(1);
    c1.takeDamage(10);
    c1.takeDamage(100);
    c1.attack("P1");
    c1.beRepaired(10);
    ScavTrap c2(c1);
    c2.attack("P1");
    ScavTrap    a;
    a.attack("P1");
    ClapTrap b;
    b.attack("P2");
    ScavTrap    p1("1");
    ScavTrap    p2("2");
    ScavTrap    p3("3");
    ScavTrap    p4("4");
}
