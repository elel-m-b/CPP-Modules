#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called\n";
    _value = 0;
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

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called \n";
    this->_value = other._value;
    return *this;
}

Fixed::Fixed(const     Fixed& other)
{
     std::cout << "copy constracteur called\n";
     _value = other._value;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called\n";
    return (_value);
}

void    Fixed::setRawBits(int const raw)
{
    _value = raw;
}

int        Fixed::toInt() const 
{
     return _value >> _fractionalBits;
}

float       Fixed::toFloat() const
{
    return static_cast<float>(_value) / (1 << _fractionalBits);
}

std::ostream&       operator<<(std::ostream &out, const Fixed &s)
{
    out << s.toFloat();
    return (out);
}

bool Fixed::operator>(const Fixed& other)
{

}
bool Fixed::operator<(const Fixed& other)
{

}
bool Fixed::operator>=(const Fixed& other)
{

}
bool Fixed::operator<=(const Fixed& other)
{

}
bool Fixed::operator==(const Fixed& other)
{

}
bool Fixed::operator!=(const Fixed& other)
{

}
Fixed::Fixed operator+(const Fixed& other)
{

}
Fixed::Fixed operator-(const Fixed& other)
{

}
Fixed::Fixed operator*(const Fixed& other)
{

}
Fixed::Fixed operator/(const Fixed& other) 
{

}

Fixed& Fixed::operator++()
{

}