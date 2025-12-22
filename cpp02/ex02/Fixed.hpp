#ifndef     FIXED_HPP
#define     FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
    private:
    int _value;
    static const int _fractionalBits = 8;

    public:
    // Default constructor
    Fixed();
    // Copy constructor
    Fixed(const Fixed& other);
    // Int constructor
    Fixed(const int value);
    // Float constructor
    Fixed(const float value);
    // Copy assignment operator
    Fixed& operator=(const Fixed& other);
    // Destructor
    ~Fixed();
    // Getters / setters
    int getRawBits(void) const;
    void setRawBits(int const raw);
    // Conversions
    float toFloat(void) const;
    int toInt(void) const;

    // ---------------- Comparison Operators ----------------
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;
    // ---------------- Arithmetic Operators ----------------
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;
    // ---------------- Increment / Decrement ----------------
    // pre-increment
    Fixed& operator++();
    // post-increment
    Fixed operator++(int);
    // pre-decrement
    Fixed& operator--();
    // post-decrement
    Fixed operator--(int);
};
std::ostream& operator<<(std::ostream& os, const Fixed& f);
#endif