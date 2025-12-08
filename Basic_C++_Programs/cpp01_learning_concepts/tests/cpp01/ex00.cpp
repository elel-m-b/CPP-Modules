#include <iostream>


class       Zombie
{
    private:
    std::string name;

    public:
    void         announce( void );
    Zombie(std::string n) :name(n) {}
    ~Zombie() {std::cout << name << " are destroyeed " << std::endl ;}
};

Zombie* newZombie( std::string name )
{
    Zombie  *c1 = new Zombie(name);
    return (c1);
}

void randomChump( std::string name )
{
    Zombie      c2(name);
    c2.announce();
}

void Zombie::announce()
{
    std::cout << name <<": BraiiiiiiinnnzzzZ..." << "\n";
}

int main(void)
{
    Zombie        *c1;
    c1 = newZombie("Heap");
    c1->announce();
    randomChump("stack");
    delete  c1;
}