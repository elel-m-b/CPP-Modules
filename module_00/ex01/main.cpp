#include <iostream>
#include <string>

#include <iostream>
#include <string>

class Contact
{
    private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneN;
    std::string darkestsecret;

    public:
    void setContact(std::string &first_name, std::string &last_name, std::string &nickname, std::string &phone, std::string &secret);
    void displayContact() const;
};

class PhoneBook
{
    private:
    Contact contact[8];
    int index = 0;
    public:
    void addContact();
    void searchContact();
    void displayContact();
};

void Contact::setContact(std::string &f, std::string &l, std::string &n, std::string &phone, std::string &secret)
{
    firstName = f;
    lastName = l;
    nickname = n;
    phoneN = phone;
    darkestsecret = secret;
}

void PhoneBook::addContact()
{
    std::string     first_name;
    std::string     last_name;
    std::string     nickname;
    std::string     phone;
    std::string     ds;
    std::cout << "Enter yout firt name: ";
    std::cin >> first_name;
    std::cout << "Enter your last name: ";
    std::cin >> last_name;
    std::cout << "Enter your nickname: ";
    std::cin >> nickname;
    std::cout << "Enter your phone number: ";
    std::cin >> phone;
    std::cout << "Enter darkest secret: ";
    std::cin >> ds;
    contact[index].setContact(first_name, last_name, nickname, phone, ds);
    index++;
}

void Contact::displayContact() const
{
    std::cout << "First Name: " << firstName << "\n";
    std::cout << "Last Name: " << lastName << "\n";
    std::cout << "Nickname: " << nickname << "\n";
    std::cout << "Phone: " << phoneN << "\n";
    std::cout << "Secret: " << darkestsecret << "\n";
}

void PhoneBook::displayContact()
{
    int     i;
    i = 0;
    while (i < 8)
    {
        contact[i].displayContact();
        i++;
    }

}
void PhoneBook::searchContact()
{
    std::cout << "Search ta lghda w nkhdmo hh\n";
}

int main()
{
    std::string command;
    PhoneBook phone;

    while (1)
    {
        std::cout << "Enter your cmd: ";
        if (!std::getline(std::cin, command))
        {
            perror("getline:");
            break;
        }
        if (command == "ADD")
            phone.addContact();
        else if (command == "SEARCH")
            phone.searchContact();
        else if (command == "EXIT")
            break;
        else
            std::cout << "ivalid argument\n";
    }

    return 0;
}