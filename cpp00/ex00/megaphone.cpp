#include <iostream>
#include <string>
#include <cctype>

class Megaphone
{
public:
    void convert_string(const std::string& str);
};

void Megaphone::convert_string(const std::string& str)
{
    for (char c : str)
        std::cout << static_cast<char>(std::toupper(c));
}

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    Megaphone speaker;

    for (int i = 1; i < ac; i++)
    {
        speaker.convert_string(av[i]);
        if (i < ac - 1)
            std::cout << " ";
    }

    std::cout << std::endl;
    return 0;
}
