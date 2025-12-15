#include <iostream>
#include <string>

// ----------------- Base Class -----------------
class Animal {
    protected:
    std::string type;
    public:
    Animal() : type("Unknown")
    {
        std::cout << "[Animal] Constructor called\n";
    }
    virtual ~Animal() 
    {
        std::cout << "[Animal] Destructor called\n";
    }

    virtual void makeSound() const 
    {
        std::cout << "[Animal] Generic animal sound!\n";
    }

    std::string getType() const 
    {
        return type;
    }
};

// ----------------- Derived Classes -----------------
class Dog : public Animal 
{
    public:
    Dog() {
        type = "Dog";
        std::cout << "[Dog] Constructor called\n";
    }
    ~Dog() 
    {
        std::cout << "[Dog] Destructor called\n";
    }

    void makeSound() const override 
    {
        std::cout << "Woof! Woof!\n";
    }
};

class Cat : public Animal {
public:
    Cat() {
        type = "Cat";
        std::cout << "[Cat] Constructor called\n";
    }
    ~Cat() {
        std::cout << "[Cat] Destructor called\n";
    }

    void makeSound() const override {
        std::cout << "Meow! Meow!\n";
    }
};

// ----------------- WrongAnimal and WrongCat -----------------
class WrongAnimal {
protected:
    std::string type;
public:
    WrongAnimal() : type("WrongAnimal") {
        std::cout << "[WrongAnimal] Constructor called\n";
    }
    ~WrongAnimal() {
        std::cout << "[WrongAnimal] Destructor called\n";
    }

    void makeSound() const {
        std::cout << "[WrongAnimal] Generic wrong animal sound!\n";
    }

    std::string getType() const {
        return type;
    }
};

class WrongCat : public WrongAnimal {
public:
    WrongCat() {
        type = "WrongCat";
        std::cout << "[WrongCat] Constructor called\n";
    }
    ~WrongCat() {
        std::cout << "[WrongCat] Destructor called\n";
    }

    void makeSound() const { // not virtual
        std::cout << "[WrongCat] Meow? (wrong sound)\n";
    }
};

// ----------------- Main Function -----------------
int main() 
{
    std::cout << "=== Correct Animals ===\n";
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;

    i->makeSound(); // Cat sound
    j->makeSound(); // Dog sound
    meta->makeSound(); // Animal sound

    delete meta;
    delete j;
    delete i;

    std::cout << "\n=== Wrong Animals ===\n";
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << std::endl;
    wrongCat->makeSound(); // Will output WrongAnimal sound because not virtual
    wrongMeta->makeSound();

    delete wrongMeta;
    delete wrongCat;

    return 0;
}
