#include "PhoneBook.hpp"
#include "Contact.hpp"

void Contact::setContact(std::string f, std::string l, std::string n, std::string phone, std::string secret)
{
    firstName = f;
    lastName = l;
    nickname = n;
    phoneN = phone;
    darkestsecret = secret;
}

std::string Contact::getFirstName() { return firstName; }
std::string Contact::getLastName() { return lastName; }
std::string Contact::getNickname() { return nickname; }
std::string Contact::getPhone() { return phoneN; }
std::string Contact::getSecret() { return darkestsecret; }

void Contact::displayContact()
{
    std::cout << "First Name: " << firstName << "\n";
    std::cout << "Last Name: " << lastName << "\n";
    std::cout << "Nickname: " << nickname << "\n";
    std::cout << "Phone: " << phoneN << "\n";
    std::cout << "Secret: " << darkestsecret << "\n";
}