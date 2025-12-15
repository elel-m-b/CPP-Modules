#include <string>
#include <iostream>



class ClapTrap 
{
    private:
    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;

    public:
    // Constructor
    ClapTrap(const std::string& _name);

    // Member functions
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

ClapTrap::ClapTrap(const std::string& _name) :name(_name), hitPoints(10), energyPoints(10), attackDamage(0) 
{
    std::cout << "ClapTrap " << name << " has been created!\n";
}
void ClapTrap::attack(const std::string& target) 
{
    if (energyPoints <= 0 || hitPoints <= 0) 
    {
        std::cout << "ClapTrap " << name << " has no energy or is dead and cannot attack.\n";
        return;
    }

    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!\n";

    energyPoints--; // ينقص طاقة ClapTrap بعد الهجوم
}

void ClapTrap::takeDamage(unsigned int amount) 
{
    if (hitPoints <= 0) 
    {
        std::cout << "ClapTrap " << name << " is already dead.\n";
        return; // إذا الصحة صفر، ما نقدروش نزيدو نقصو
    }

    // نقص الصحة بمقدار الضرر
    hitPoints -= amount;

    // ما نخليش hitPoints يكون سلبي
    if (hitPoints < 0)
        hitPoints = 0;

    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage. " << "Current HP: " << hitPoints << "\n";
}

void ClapTrap::beRepaired(unsigned int amount) 
{
    // التحقق من الحالة
    if (energyPoints <= 0 || hitPoints <= 0) 
    {
        std::cout << "ClapTrap " << name << " has no energy or is dead and cannot repair.\n";
        return; // ما نقدرش يصلح راسو إذا الطاقة صفر أو مات
    }

    // زيادة hit points بمقدار amount
    hitPoints += amount;

    // نقص وحدة من الطاقة بعد كل إصلاح
    energyPoints--;

    // طباعة حالة ClapTrap بعد الإصلاح
    std::cout << "ClapTrap " << name << " is repaired by " << amount  << " points. Current HP: " << hitPoints << "\n";
}

int main()
{
    ClapTrap clap("CL4P-TP");

    clap.attack("Target1"); // ndiro attack w n9so energie dyalo 
    clap.takeDamage(5); // nn9so si7a dyalo hit point 
    clap.beRepaired(3); // nzido si7a dylo w nn9o energie dyalo w ntb30 l7ala dyalo 
    clap.takeDamage(10); // nn9so si7a dyalo 
    clap.beRepaired(2); // nzido si7a dyalo 
}