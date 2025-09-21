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
    void setContact(std::string &first_name, std::string &last_name, std::string &nickname, std::string &phone, std::string &secret);
    void displayContact();
    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    std::string getNickname() const { return nickname; }
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

void Contact::displayContact()
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
std::string formatField(const std::string &str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return std::string(10 - str.length(), ' ') + str;
}

void PhoneBook::searchContact()
{
    if (index == 0)
    {
        std::cout << "PhoneBook is empty.\n";
        return;
    }

    // 1. Display header
    std::cout << "---------------------------------------------\n";
    std::cout << "|   Index  |First Name| Last Name| Nickname |\n";
    std::cout << "---------------------------------------------\n";

    // 2. Display each contact in table format
    for (int i = 0; i < index && i < 8; i++)
    {
        std::cout << "|" << std::setw(10) << i
                  << "|" << formatField(contact[i].getFirstName())
                  << "|" << formatField(contact[i].getLastName())
                  << "|" << formatField(contact[i].getNickname())
                  << "|\n";
    }
    std::cout << "---------------------------------------------\n";

    // 3. Ask user for index
    std::cout << "Enter the index of the contact to display: ";
    int idx;
    if (!(std::cin >> idx) || idx < 0 || idx >= index)
    {
        std::cout << "Invalid index.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    // 4. Display full contact info
    contact[idx].displayContact();

    // clean up leftover newline so getline() works again
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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