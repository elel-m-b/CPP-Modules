#include "ClapTrap.hpp"

int main()
{
    ClapTrap m;
    ClapTrap    a("R1");
    ClapTrap    b("R2");
    ClapTrap    c("R3");
    ClapTrap    d("R4");

    a.takeDamage(10);
    a.beRepaired(1);
    a.beRepaired(20); 
    a.attack("P1");
    a.takeDamage(20);
    a.takeDamage(10);
    a.attack("P4");
    a.takeDamage(1);
    return 0;
}
