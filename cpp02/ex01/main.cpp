#include <iostream>
#include <cmath>

class Fixed
{
    private:
    int _value;
    static const int _fractionalBits = 8;

    public:
    // Default constructor
    Fixed()
    {
        std::cout << "Default constructor called\n";
        _value = 0;
    }

    // Copy constructor
    Fixed(const Fixed& other)
    {
        std::cout << "Copy constructor called\n";
        _value = other._value;
    }

    // Int constructor
    Fixed(const int value)
    {
        std::cout << "Int constructor called\n";
        _value = value << _fractionalBits;
    }

    // Float constructor
    Fixed(const float value)
    {
        std::cout << "Float constructor called\n";
        _value = roundf(value * (1 << _fractionalBits));
    }

    // Copy assignment operator
    Fixed& operator=(const Fixed& other)
    {
        std::cout << "Copy assignment operator called\n";
        if (this != &other)
            _value = other._value;
        return *this;
    }

    // Destructor
    ~Fixed()
    {
        std::cout << "Destructor called\n";
    }

    // Getters / setters
    int getRawBits(void) const
    {
        return _value;
    }

    void setRawBits(int const raw)
    {
        _value = raw;
    }

    // Conversions
    float toFloat(void) const
    {
        return static_cast<float>(_value) / (1 << _fractionalBits);
    }

    int toInt(void) const
    {
        return _value >> _fractionalBits;
    }
};

// Operator <<
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

int main()
{
    Fixed a(10);
    Fixed b(42.42f);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    return 0;
}
