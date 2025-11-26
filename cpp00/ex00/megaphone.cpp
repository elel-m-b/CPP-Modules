#include <iostream>
#include <string>


int main(int   ac, char **av)
{
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    std::string         name;

    for(int i = 1; i < ac; i++)
    {
        name = av[i];
        for (size_t j = 0; j < name.length(); j++)
            name[j] = std::toupper(name[j]);
        std::cout << name;
    }
    return (0);
}

