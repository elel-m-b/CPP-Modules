#include <iostream>
#include <string>

// Unnecessary violence

class Weapon
{
    private:
    std::string type;

    public:
    Weapon(std::string& initialType);
    void setType(std::string& newType);
    std::string& getType();
};

class HumanA
{
    private:
    std::string name;
    Weapon& weapon; // reference because HumanA is always armed

    public:
    HumanA(std::string& name, Weapon& weapon);
    void attack();
};

class HumanB
{
    private:
    std::string name;
    Weapon* weapon; // pointer because HumanB may have no weapon initially

    public:
    HumanB(std::string& name);
    void setWeapon(Weapon& newWeapon);
    void attack();
};

// ---------------- IMPLEMENTATION ----------------

Weapon::Weapon(std::string& initialType)
{
    type = initialType;
}

void Weapon::setType(std::string& newType)

    type = newType;
}

std::string& Weapon::getType() 
{
    return type;
}

HumanA::HumanA(std::string& name, Weapon& weapon) : name(name), weapon(weapon)
{
}

void HumanA::attack() 
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

HumanB::HumanB(std::string& name)
    : name(name), weapon(NULL)
{
}

void HumanB::setWeapon(Weapon& newWeapon)
{
    weapon = &newWeapon;
}

void HumanB::attack() 
{
    if (weapon)
        std::cout << name << " attacks with their "<< weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon to attack with" << std::endl;
}

// ---------------- MAIN ----------------

int main()
{
    {
        Weapon club("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}
