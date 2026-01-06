#include <iostream>

class Animal
{
    protected:
    std::string type;

    public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    ~Animal();
    virtual void makeSound() const;
    std::string getType() const;
};

class Dog : public Animal
{
    public:
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog();
    void makeSound() const;
};

class Cat : public Animal
{
    public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat();

    void makeSound() const;
};

std::string Animal::getType() const
{
    return (type);
}

Animal::Animal() : type("Animal")
{
    std::cout << "Animal Default constructor called" << std::endl;
}
Animal::Animal(const Animal& other)
{
    std::cout << "Animal Copy constructor called" << std::endl;
    type = other.type;
}
Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal Copy assignment operator called" << std::endl;
    if (this != &other)
        type = other.type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}
void Animal::makeSound() const
{
    std::cout << "Animal makes an undefined sound" << std::endl;
}
Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Dog Woof! Woof!" << std::endl;
}

Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat Default constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat Copy constructor called" << std::endl;
}
Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
}
void Cat::makeSound() const
{
    std::cout << "Cat Meow~" << std::endl;
}


int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    j->makeSound(); //will output the cat sound!
    j->makeSound(); 
    meta->makeSound();
    delete meta;
    delete j;
    delete i;
}