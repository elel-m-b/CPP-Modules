#include <iostream>
#include <cctype>

class test
{
public:
    void change_args(std::string &arg);
};

void test::change_args(std::string &arg)
{
    for (unsigned int  i = 0; i < arg.size(); i++)
        arg[i] = std::toupper(arg[i]);
}


int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    test a;
    std::string name;
    for (int i = 1; i < ac; i++)
    {
        name = av[i];  
        a.change_args(name); 
        std::cout << name << std::endl;
    }
}

