#include "ClapTrap.hpp"

int main()
{
    std::cout << "=== CREATE CLAPTRAP ===\n";
    ClapTrap clap("R1");

    std::cout << "\n=== TEST ATTACK ===\n";
    clap.attack("Hassan"); // normal attack

    std::cout << "\n=== TEST TAKE DAMAGE ===\n";
    clap.takeDamage(5);   // normal damage
    clap.takeDamage(10);  // overkill damage → should set HP to 0

    std::cout << "\n=== TEST ATTACK WITH 0 ENERGY/HP ===\n";
    clap.attack("Hassan");   // should print cannot attack
    clap.beRepaired(10);     // should print cannot repair

    std::cout << "\n=== TEST REPAIR NORMAL ===\n";
    ClapTrap clap2("R2");
    clap2.attack("Target");  // reduce 1 energy
    clap2.beRepaired(5);     // increase HP by 5, reduce 1 energy
    clap2.takeDamage(3);     // reduce HP

    std::cout << "\n=== TEST COPY CONSTRUCTOR ===\n";
    ClapTrap clapCopy(clap2);  // copy constructor
    clapCopy.attack("Enemy");

    std::cout << "\n=== TEST ASSIGNMENT OPERATOR ===\n";
    ClapTrap clapAssign("Temp");
    clapAssign = clap2;        // copy assignment
    clapAssign.beRepaired(2);

    std::cout << "\n=== END OF TESTS ===\n";
    return 0;
}
