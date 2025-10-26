
#include <iostream>
#include <string>

class       megaphone
{
    public :
    void        convert_string(std::string str);
};

int main(int        ac, char        **av)
{
    if (ac < 2)
        return (0);
    int     i;
    i = 0;
    int     j = 1;
    while (av[j])
    {
        std::string      original = av[j];
        while (original[i])
        {
            if ((original[i] >= 'a' && original[i] <= 'z'))
                original[i] -= 32;
            i++;
        }
        i = 0;
        while (original[i])
        {
            std::cout << original[i];
            i++;
        }
        j++;
    }
    return (1);
}