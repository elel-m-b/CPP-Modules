#include <iostream>
#include <string>

class      PhoneBook
{
    public:
        std::string     first_name;
        std::string     last_name;
        std::string     nickname;
        std::string     phone_number;
    // public:
    //     void        fill_contact(std::string info)
    //     {
    //         first_name = info;
    //     }
};

class      Contact
{
    public:
        PhoneBook       call;
    
};

int main(int        ac, char        **av)
{
    if (ac == 1)
        return (0);
    std::string     command = av[1];
    Contact     p;
    while (1)
    {
        if (command == "ADD")
        {
            std::cout << "Enter your contact\n";
            std::cin >> p.call.first_name;
        }
    }
}