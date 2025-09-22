#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

class Contact
{
    private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneN;
    std::string darkestsecret;

    public:
    void setContact(std::string f, std::string l, std::string n, std::string phone, std::string secret);
    std::string getFirstName();
    std::string getLastName();
    std::string getNickname();
    std::string getPhone();
    std::string getSecret();
    void displayContact();
};
#endif 