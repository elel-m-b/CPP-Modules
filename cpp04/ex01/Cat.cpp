#include "Cat.hpp"
#include "Brain.hpp"
Cat::Cat()
{
    std::cout << "Cat Default constructor called" << std::endl;
    type = "Cat";
    brain = new Brain();
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        brain = new Brain();
        Animal::operator=(other);
    }
    return *this;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    brain = new Brain(*other.brain);
    std::cout << "Cat Copy constructor called" << std::endl;
}
Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
    delete brain;
}

void Cat::makeSound() const
{
    std::cout << "Cat Meow~" << std::endl;
}
