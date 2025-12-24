#include "Fixed.hpp"
#include <cmath>

/* ---------------- Constructors ---------------- */
Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int val)
{
    _value = val << _fractionalBits;
}

Fixed::Fixed(const float val)
{
    _value = roundf(val * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
    _value = other._value;
}

/* ---------------- Assignment ---------------- */
Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        _value = other._value;
    return *this;
}

/* ---------------- Conversion ---------------- */
float Fixed::toFloat() const
{
    return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt() const
{
    return _value >> _fractionalBits;
}

/* ---------------- Comparison Operators ---------------- */
bool Fixed::operator>(const Fixed& other) const { return _value > other._value; }
bool Fixed::operator<(const Fixed& other) const { return _value < other._value; }
bool Fixed::operator>=(const Fixed& other) const { return _value >= other._value; }
bool Fixed::operator<=(const Fixed& other) const { return _value <= other._value; }
bool Fixed::operator==(const Fixed& other) const { return _value == other._value; }
bool Fixed::operator!=(const Fixed& other) const { return _value != other._value; }

/* ---------------- Arithmetic Operators ---------------- */
Fixed Fixed::operator+(const Fixed& other) const { return Fixed(this->toFloat() + other.toFloat()); }
Fixed Fixed::operator-(const Fixed& other) const { return Fixed(this->toFloat() - other.toFloat()); }
Fixed Fixed::operator*(const Fixed& other) const { return Fixed(this->toFloat() * other.toFloat()); }
Fixed Fixed::operator/(const Fixed& other) const { return Fixed(this->toFloat() / other.toFloat()); }

/* ---------------- Increment / Decrement ---------------- */
Fixed& Fixed::operator++() { _value += 1; return *this; }     // pre-increment
Fixed Fixed::operator++(int) { Fixed temp(*this); _value += 1; return temp; } // post-increment
Fixed& Fixed::operator--() { _value -= 1; return *this; }     // pre-decrement
Fixed Fixed::operator--(int) { Fixed temp(*this); _value -= 1; return temp; } // post-decrement

/* ---------------- Stream operator ---------------- */
std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
    os << f.toFloat();
    return os;
}
