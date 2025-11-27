#include "PhoneBook.hpp"
#include "Contact.hpp"

int PhoneBook::isNumber(const std::string str)
{
    if (str.empty())
        return (0);
    for (size_t i = 0; i < str.length(); i++)
        if (!isdigit(str[i]))
            return (0);
    return (1);
}

PhoneBook::PhoneBook()
{
    index = 0;
    count = 0;
}

std::string PhoneBook::formatField(std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::addContact()
{
    std::string first_name, last_name, nickname, phone, ds;

    std::cout << "Enter your first name: ";
    while (1) 
    {
        if (!std::getline(std::cin, first_name))
            return;
        if (!first_name.empty())
            break;
        std::cout << "First name cannot be empty. Enter your first name: ";
    }

    std::cout << "Enter your last name: ";
    while (1) 
    {
        if (!std::getline(std::cin, last_name))
            return;
        if (!last_name.empty())
            break;
        std::cout << "Last name cannot be empty. Enter your last name: ";
    }

    std::cout << "Enter your nickname: ";
    while (1) 
    {
        if (!std::getline(std::cin, nickname))
            return;
        if (!nickname.empty())
            break;
        std::cout << "Nickname cannot be empty. Enter your nickname: ";
    }

    std::cout << "Enter your phone number: ";
    while (1) 
    {
        if (!std::getline(std::cin, phone))
            return;
        if (!phone.empty() && isNumber(phone))
            break;
        std::cout << "Phone number must be digits and not empty. Enter your phone number: ";
    }

    std::cout << "Enter darkest secret: ";
    while (1) 
    {
        if (!std::getline(std::cin, ds))
            return;
        if (!ds.empty())
            break;
        std::cout << "Darkest secret cannot be empty. Enter your darkest secret: ";
    }

    contact[index].setContact(first_name, last_name, nickname, phone, ds);
    index = (index + 1) % 8;
    if (count < 8) count++;
}




void PhoneBook::searchContact()
{
    if (count == 0)
    {
        std::cout << "PhoneBook is empty" << std::endl;
        return;
    }

    std::cout << "     Index|First Name| Last Name|  Nickname\n";

    for (int i = 0; i < count; i++)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << formatField(contact[i].getFirstName()) << "|"
                  << std::setw(10) << formatField(contact[i].getLastName()) << "|"
                  << std::setw(10) << formatField(contact[i].getNickname())
                  << std::endl;
    }

    int idx = -1;
    std::string input;

    while (1)
    {
        std::cout << "Enter an index: ";
        if (!std::getline(std::cin, input))
            return ;

        std::stringstream ss(input);

        ss >> idx;
        if (idx < 0 || idx >= count || !ss.eof())
        {
            std::cout << "Invalid input! " << std::endl;
            continue;
        }
        break;
    }

    contact[idx].displayContact();
}