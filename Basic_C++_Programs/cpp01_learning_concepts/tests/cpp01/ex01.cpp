#include <iostream>



class       Zombie
{
    private:
    std::string     name;
    public:
    Zombie();
   ~Zombie() { std::cout << name << " destroyed\n"; }
    void        announce(void);
    void    setName(std::string name);
};

Zombie::Zombie(){};

void Zombie::setName(std::string n)
{
    name = n;
}

Zombie* zombieHorde(int N, std::string name)
{
    Zombie* c1 = new Zombie[N];
    for (int i = 0; i < N; i++)
        c1[i].setName(name);
    return (c1);
}

void Zombie::announce() 
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

int main(void)
{
    int         N = 5;
    Zombie  *c1 = zombieHorde(N, "Heap");
    for (int i = 0; i < N; i++)
        c1[i].announce();
    delete[] c1;
}