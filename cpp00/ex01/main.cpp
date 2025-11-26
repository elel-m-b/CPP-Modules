#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
    std::string command;
    PhoneBook phone;

    while (1)
    {
        std::cout << "Enter your cmd:(ADD), (SEARCH), (EXIT): ";
        if (!std::getline(std::cin, command))
            break;
        if (command == "ADD")
            phone.addContact();
        else if (command == "SEARCH")
            phone.searchContact();
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command\n";
    }
    return 0;
}