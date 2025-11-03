#include <iostream>


class Zombie
{
    public:
        void        announce(void)
        {
            std::cout <<  name << ": BraiiiiiiinnnzzzZ..." << std::endl;
        }
        void    setName(std::string n)
        {
            name = n;
        }
    private:
        std::string     name;
};

Zombie* newZombie( std::string name )
{

}

void randomChump( std::string name )
{

}

int main()
{

}