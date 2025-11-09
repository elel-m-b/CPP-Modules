#include "PhoneBook.hpp"
#include "Contact.hpp"

int PhoneBook::isNumber(const std::string &str)
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
    std::getline(std::cin, first_name);
    std::cout << "Enter your last name: ";
    std::getline(std::cin, last_name);
    std::cout << "Enter your nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Enter your phone number: ";
    std::getline(std::cin, phone);
    while (!isNumber(phone))
    {
        std::cout << "Invalid input! Phone number must contain only digits.\n";
        std::cout << "Enter your phone number: ";
        std::getline(std::cin, phone);
    }
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, ds);
    contact[index].setContact(first_name, last_name, nickname, phone, ds);
    index = (index + 1) % 8;
    if (count < 8) count++;
}


void PhoneBook::searchContact()
{
    if (count == 0)
    {
        std::cout << "PhoneBook is empty.\n";
        return;
    }

    std::cout << "     Index|First Name| Last Name|  Nickname\n";

    for (int i = 0; i < count; i++)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << formatField(contact[i].getFirstName()) << "|"
                  << std::setw(10) << formatField(contact[i].getLastName()) << "|"
                  << std::setw(10) << formatField(contact[i].getNickname()) << "\n";
    }

    int idx;
    while (1)
    {
        std::cout << "Enter the index of the contact to display: ";
        std::string input;
        std::getline(std::cin, input);

        bool valid = !input.empty();
        for (size_t i = 0; i < input.length() && valid; i++)
            if (!isdigit(input[i]))
                valid = false;

        if (!valid)
        {
            std::cout << "Invalid input! Index must be a number.\n";
            continue;
        }
        std::stringstream ss(input);
        ss >> idx;

        if (ss.fail() || !ss.eof())
        {
            std::cout << "Invalid input! Conversion failed.\n";
            continue;
        }

        if (idx < 0 || idx >= count)
        {
            std::cout << "Invalid input! Index out of range.\n";
            continue;
        }
        break;
    }

    contact[idx].displayContact();
}

void PhoneBook::displayContact()
{
    for (int i = 0; i < count; i++)
    {
        contact[i].displayContact();
        std::cout << "------------------------\n";
    }
}
