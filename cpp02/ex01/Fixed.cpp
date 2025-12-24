#include "Fixed.hpp"
#include <cmath>

/* Constructors */

Fixed::Fixed()
{
    std::cout << "Default constructor called\n";
    _value = 0;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called\n";
    _value = other._value;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called\n";
    _value = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called\n";
    _value = roundf(value * (1 << _fractionalBits));
}

/* Assignment operator */

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &other)
        _value = other._value;
    return *this;
}

/* Destructor */

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

/* Getters / setters */

int Fixed::getRawBits(void) const
{
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
}

/* Conversions */

float Fixed::toFloat(void) const
{
    return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return _value >> _fractionalBits;
}

/* Operator << overload */

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}
