#include <iostream>
#include <string>

// Unnecessary violence

class Weapon
{
    private:
    std::string type;

    public:
    Weapon(const std::string& initialType);
    void setType(const std::string& newType);
    const std::string& getType();
};

class HumanA
{
    private:
    std::string name;
    Weapon& weapon;

    public:
    HumanA(const std::string& name, Weapon& weapon);
    void attack();
};

class HumanB
{
    private:
    std::string name;
    Weapon* weapon;

    public:
    HumanB(const std::string& name);
    void setWeapon(Weapon& newWeapon);
    void attack();
};

// ---------------- IMPLEMENTATION ----------------

Weapon::Weapon(const std::string& initialType)
{
    type = initialType;
}

void Weapon::setType(const std::string& newType)
{
    type = newType;
}

const std::string& Weapon::getType()
{
    return type;
}

HumanA::HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon)
{
}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

HumanB::HumanB(const std::string& name)
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
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
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
}
