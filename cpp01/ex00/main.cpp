#include "Zombie.hpp"
int main() 
{
    Zombie* heapZombie = newZombie("Heap");
    heapZombie->announce();
    delete heapZombie;
    randomChump("stack");
    return 0;
}
