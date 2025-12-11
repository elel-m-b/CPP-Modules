//ex01

/*
    👉 You can only create a dynamic array of objects on the heap,
    not on the stack if the size is unknown at compile time.
*/

#include <iostream>

class Zombie {
private:
    std::string name;

    public:
    Zombie() {}  // default constructor

    ~Zombie() // // destructor
    { 
        std::cout << this->name << " is destroyed." << std::endl;
    }

    void setName(std::string name) 
    {
        this->name = name;
    }

    void announce() 
    {
        std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    }
};

// ------------------------------
// Create a horde of N zombies
// ------------------------------

Zombie* zombieHorde(int N, std::string name) 
{
    if (N <= 0)
        return NULL;

    Zombie* horde = new Zombie[N];

    for (int i = 0; i < N; i++)
        horde[i].setName(name);

    return horde;
}

// ------------------------------
// Test the horde
// ------------------------------
int main() 
{
    int N = 5;

    Zombie* horde = zombieHorde(N, "Walker");

    for (int i = 0; i < N; i++)
        horde[i].announce();

    delete[] horde;    // VERY IMPORTANT: destroy all zombies

    return 0;
}


