#include <iostream>

#include "sed.hpp"

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Usage: " << " <filename> <s1> <s2> " << std::endl;
        return (1);
    }
    std::string     filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    Sed sed(filename, s1, s2);
    sed.replaceInFile();
    return (0);
}