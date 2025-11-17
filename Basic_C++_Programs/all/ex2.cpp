#include <iostream>


namespace Physics
{
    int     energy(int      mass, int speed)
    {
        return (0.5 * mass * (speed * speed));
    }
}
namespace       Chemistry
{
    int moles(int mass, double  molarMass)
    {
        return (mass / molarMass);
    }
}

int main(void)
{
    int r1 = Physics::energy(1, 2);
    int r2 = Chemistry::moles(1, 4);
    std::cout << "r1 == " << r1 << "\n" << "r2 == " << r2 << std::endl;
    return (0);
}