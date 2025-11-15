#include <iostream>
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main()
{
    int     N = 5;
    Zombie  *ptr = zombieHorde(N, "Hassan");
    for (int i = 0; i < N; i++)
        ptr[i].announce();
    delete[] ptr;
    return (0);
}