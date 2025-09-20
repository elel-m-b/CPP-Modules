#include <iostream>
#include <string>

class PhoneBook
{
    public:
        int     contact[8];
        std::string name;

};

class   contact
{

};

int main(int    ac, char        **av)
{
    std::string     input;
    PhoneBook       object;
    while (1)
    {
        std::cout << "Enter the command : ";
        getline(std::cin, input);
        if (input == "ADD")
            std::cout << "THE COMMAND ADD\n";
        else if (input == "SEARCH")
            std::cout << "THE COMMAND ARE SERCCH\n";
        else if (input == "EXIT")
            std::cout << "must exit\n";
        else
            std::cout << "INVALID COMMAND\n";
    }
    return (0);
}