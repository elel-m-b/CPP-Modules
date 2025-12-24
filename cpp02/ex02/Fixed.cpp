#include "Fixed.hpp"
#include <cmath>
#include <iostream>

// ====================
// Constructors & Destructor
// ====================

// Default constructor: initialize value to 0
Fixed::Fixed() : _value(0) {}

// Construct from integer: shift left by fractional bits
Fixed::Fixed(const int n) : _value(n << _fractionalBits) {}

// Construct from float: multiply and round to nearest integer
Fixed::Fixed(const float f) 
    : _value(roundf(f * (1 << _fractionalBits))) {}

// Copy constructor: copy the internal value
Fixed::Fixed(const Fixed &other) : _value(other._value) {}

// Destructor
Fixed::~Fixed() {}

// ====================
// Assignment Operator
// ====================
Fixed &Fixed::operator=(const Fixed &other) 
{
    if (this != &other)  // avoid self-assignment
        _value = other._value;
    return *this;
}

// ====================
// Comparison Operators
// ====================
bool Fixed::operator>(const Fixed &other) const { return _value > other._value; }
bool Fixed::operator<(const Fixed &other) const { return _value < other._value; }
bool Fixed::operator>=(const Fixed &other) const { return _value >= other._value; }
bool Fixed::operator<=(const Fixed &other) const { return _value <= other._value; }
bool Fixed::operator==(const Fixed &other) const { return _value == other._value; }
bool Fixed::operator!=(const Fixed &other) const { return _value != other._value; }

// ====================
// Arithmetic Operators
// ====================
Fixed Fixed::operator+(const Fixed &other) const { return Fixed(toFloat() + other.toFloat()); }
Fixed Fixed::operator-(const Fixed &other) const { return Fixed(toFloat() - other.toFloat()); }
Fixed Fixed::operator*(const Fixed &other) const { return Fixed(toFloat() * other.toFloat()); }
Fixed Fixed::operator/(const Fixed &other) const { return Fixed(toFloat() / other.toFloat()); }

// ====================
// Increment / Decrement
// ====================

// Pre-increment: ++x
Fixed &Fixed::operator++() 
{ 
    _value++;
    return *this;
}

// Post-increment: x++
Fixed Fixed::operator++(int) 
{ 
    Fixed tmp(*this);
    _value++;
    return tmp;
}

// Pre-decrement: --x
Fixed &Fixed::operator--() 
{ 
    _value--;
    return *this;
}

// Post-decrement: x--
Fixed Fixed::operator--(int) 
{ 
    Fixed tmp(*this);
    _value--;
    return tmp;
}

// ====================
// Getters / Setters
// ====================
int Fixed::getRawBits() const { return _value; }
void Fixed::setRawBits(int const raw) { _value = raw; }

// Convert fixed-point value to float
float Fixed::toFloat() const { return (float)_value / (1 << _fractionalBits); }

// Convert fixed-point value to integer (truncates)
int Fixed::toInt() const { return _value >> _fractionalBits; }

// ====================
// Min / Max Functions
// ====================

// Return the smaller of two non-const Fixed objects
Fixed &Fixed::min(Fixed &a, Fixed &b) 
{
    if (a < b)
        return a;
    return b;
}

// Return the smaller of two const Fixed objects
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) 
{
    if (a < b)
        return a;
    return b;
}

// Return the larger of two non-const Fixed objects
Fixed &Fixed::max(Fixed &a, Fixed &b) 
{
    if (a > b)
        return a;
    return b;
}

// Return the larger of two const Fixed objects
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) 
{
    if (a > b)
        return a;
    return b;
}

// ====================
// Output Stream Overload
// ====================
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) 
{
    out << fixed.toFloat();  // output as float
    return out;
}
