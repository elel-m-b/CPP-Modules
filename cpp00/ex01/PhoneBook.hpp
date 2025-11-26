#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cstdlib>

class PhoneBook
{
    private:
    Contact contact[8];
    int index;
    int count;
    public:
    PhoneBook();
    std::string formatField(std::string str);
    void addContact();
    void searchContact();
    void displayContact();
    int isNumber(const std::string str);
};
#endif