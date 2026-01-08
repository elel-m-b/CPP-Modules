#include "WrongCat.hpp"

WrongCat::WrongCat() 
{
    type = "WrongCat";
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) 
{
    type = other.type;
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) 
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    if (this != &other) 
    {
        WrongAnimal::operator=(other);
        type = other.type;
    }
    return *this;
}

WrongCat::~WrongCat() 
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const 
{
    std::cout << "WrongCat makes a wrong cat sound" << std::endl;
}
