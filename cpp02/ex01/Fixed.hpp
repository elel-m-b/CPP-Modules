#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int _value;
    static const int _fractionalBits;

public:
    // Constructors
    Fixed();
    Fixed(const Fixed& other);
    Fixed(const int value);
    Fixed(const float value);

    // Assignment
    Fixed& operator=(const Fixed& other);

    // Destructor
    ~Fixed();

    // Getters / setters
    int getRawBits(void) const; 
    void setRawBits(int const raw); 

    // Conversions
    float toFloat(void) const;
    int toInt(void) const;
};

// Operator overload
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
