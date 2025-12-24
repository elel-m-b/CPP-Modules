#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int _value;
    static const int _fractionalBits = 8;

public:
    // ---------------- Constructors ----------------
    Fixed();
    Fixed(const int val);
    Fixed(const float val);
    Fixed(const Fixed& other);

    // ---------------- Assignment ----------------
    Fixed& operator=(const Fixed& other);

    // ---------------- Conversion ----------------
    float toFloat() const;
    int toInt() const;

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
    Fixed& operator++();    // pre-increment
    Fixed operator++(int);  // post-increment
    Fixed& operator--();    // pre-decrement
    Fixed operator--(int);  // post-decrement

    // ---------------- Stream operator ----------------
    friend std::ostream& operator<<(std::ostream& os, const Fixed& f);
};

#endif
