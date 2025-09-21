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

class PhoneBook
{
    private:
    Contact contact[8];
    int index;
    int count;

    std::string formatField(std::string str);

    public:
    PhoneBook();
    void addContact();
    void searchContact();
    void displayContact();
};

// -------------------- Contact methods --------------------

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

    std::cout << "Enter the index of the contact to display: ";
    int idx;
    std::cin >> idx;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear newline

    if (idx < 0 || idx >= count)
    {
        std::cout << "Invalid index!\n";
        return;
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

int main()
{
    std::string command;
    PhoneBook phone;

    while (true)
    {
        std::cout << "Enter your cmd: ";
        if (!std::getline(std::cin, command))
            break;

        if (command == "ADD")
            phone.addContact();
        else if (command == "SEARCH")
            phone.searchContact();
        else if (command == "DISPLAY")
            phone.displayContact();
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command\n";
    }
    return 0;
}