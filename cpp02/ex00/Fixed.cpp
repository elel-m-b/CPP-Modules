#include "Fixed.hpp"

/* static member definition */
const int Fixed::integer = 8;

/* Constructors / Destructor */

Fixed::Fixed()
{
    std::cout << "Default constructor called\n";
    _value = 0;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "copy constracteur called\n";
    _value = other._value;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

/* Operator overload */

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called \n";
    this->_value = other._value;
    return *this;
}

/* Member functions */

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
}
