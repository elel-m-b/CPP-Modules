#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() 
{
    Zombie* heapZombie = newZombie("Hassan");
    heapZombie->announce();
    delete heapZombie;
    randomChump("Aymane");
    return 0;
}
