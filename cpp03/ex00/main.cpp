#include "ClapTrap.hpp"

int main()
{
    ClapTrap        c1("R1");
    c1.attack("T1");
    c1.takeDamage(10);
    c1.attack("T1");
    c1.takeDamage(10);
    ClapTrap    c2(c1);
    c2.attack("S1");
    return 0;
}
