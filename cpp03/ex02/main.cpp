#include <iostream>
#include <string>

// =================== ClapTrap Class ===================
class ClapTrap 
{
    protected: 
    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;

    public:
    // Constructor
    ClapTrap(const std::string& _name);

    // Copy constructor
    ClapTrap(const ClapTrap& other);

    // Destructor
    ~ClapTrap();

    // Member functions
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

// =================== ClapTrap Implementation ===================
ClapTrap::ClapTrap(const std::string& _name): name(_name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " has been created!\n";
}

ClapTrap::ClapTrap(const ClapTrap& other): name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
    std::cout << "ClapTrap " << name << " has been copied!\n";
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " has been destroyed!\n";
}

void ClapTrap::attack(const std::string& target) 
{
    if (energyPoints <= 0 || hitPoints <= 0) 
    {
        std::cout << "ClapTrap " << name << " has no energy or is dead and cannot attack.\n";
        return;
    }

    std::cout << "ClapTrap " << name << " attacks " << target
              << ", causing " << attackDamage << " points of damage!\n";
    energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) 
{
    if (hitPoints <= 0) 
    {
        std::cout << "ClapTrap " << name << " is already dead.\n";
        return;
    }

    hitPoints -= amount;
    if (hitPoints < 0)
        hitPoints = 0;

    std::cout << "ClapTrap " << name << " takes " << amount
              << " points of damage. Current HP: " << hitPoints << "\n";
}

void ClapTrap::beRepaired(unsigned int amount) 
{
    if (energyPoints <= 0 || hitPoints <= 0) 
    {
        std::cout << "ClapTrap " << name << " has no energy or is dead and cannot repair.\n";
        return;
    }

    hitPoints += amount;
    energyPoints--;

    std::cout << "ClapTrap " << name << " is repaired by " << amount
              << " points. Current HP: " << hitPoints << "\n";
}

// =================== ScavTrap Class ===================
class ScavTrap : public ClapTrap 
{
    public:
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& other);
    ~ScavTrap();

    void attack(const std::string& target);
    void guardGate();
};

// =================== ScavTrap Implementation ===================
ScavTrap::ScavTrap(const std::string& _name) : ClapTrap(_name)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " has been created!\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    std::cout << "ScavTrap " << name << " has been copied!\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " has been destroyed!\n";
}

void ScavTrap::attack(const std::string& target)
{
    if (energyPoints <= 0 || hitPoints <= 0) 
    {
        std::cout << "ScavTrap " << name << " has no energy or is dead and cannot attack.\n";
        return;
    }

    std::cout << "ScavTrap " << name << " attacks " << target
              << ", causing " << attackDamage << " points of damage!\n";
    energyPoints--;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode!\n";
}

// =================== FragTrap Class ===================
class FragTrap : public ClapTrap 
{
    public:
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& other);
    ~FragTrap();

    void attack(const std::string& target);
    void highFivesGuys();
};

// =================== FragTrap Implementation ===================
FragTrap::FragTrap(const std::string& _name) : ClapTrap(_name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " has been created!\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    std::cout << "FragTrap " << name << " has been copied!\n";
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " has been destroyed!\n";
}

void FragTrap::attack(const std::string& target)
{
    if (energyPoints <= 0 || hitPoints <= 0)
    {
        std::cout << "FragTrap " << name << " has no energy or is dead and cannot attack.\n";
        return;
    }

    std::cout << "FragTrap " << name << " attacks " << target
              << ", causing " << attackDamage << " points of damage!\n";
    energyPoints--;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << name << " requests a high five!\n";
}

// =================== Main Function ===================
int main() 
{
    std::cout << "--- ClapTrap Test ---\n";
    ClapTrap clap("CL4P-TP");
    clap.attack("target1");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << "\n--- ScavTrap Test ---\n";
    ScavTrap scav("SC4V-TP");
    scav.attack("enemy1");
    scav.takeDamage(30);
    scav.beRepaired(20);
    scav.guardGate();

    std::cout << "\n--- Copy ScavTrap ---\n";
    ScavTrap scav2 = scav;
    scav2.attack("enemy2");
    scav2.guardGate();

    std::cout << "\n--- FragTrap Test ---\n";
    FragTrap frag("FR4G-TP");
    frag.attack("enemy3");
    frag.takeDamage(40);
    frag.beRepaired(25);
    frag.highFivesGuys();

    std::cout << "\n--- Copy FragTrap ---\n";
    FragTrap frag2 = frag;
    frag2.attack("enemy4");
    frag2.highFivesGuys();

    return 0;
}
