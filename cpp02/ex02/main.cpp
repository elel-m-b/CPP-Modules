#include <iostream>
#include <cmath>

class Fixed
{
    private:
    int _value;
    static const int _fractionalBits = 8;

    public:
    // ---------------- Constructors ----------------
    Fixed() : _value(0) {}
    Fixed(const int val) : _value(val << _fractionalBits) {}
    Fixed(const float val) : _value(roundf(val * (1 << _fractionalBits))) {}
    Fixed(const Fixed& other) : _value(other._value) {}

    // ---------------- Assignment ----------------
    Fixed& operator=(const Fixed& other)
    {
        if (this != &other)
            _value = other._value;
        return *this;
    }

    // ---------------- Conversion ----------------
    float toFloat() const { return static_cast<float>(_value) / (1 << _fractionalBits); }
    int toInt() const { return _value >> _fractionalBits; }

    // ---------------- Comparison Operators ----------------
    bool operator>(const Fixed& other) const { return _value > other._value; }
    bool operator<(const Fixed& other) const { return _value < other._value; }
    bool operator>=(const Fixed& other) const { return _value >= other._value; }
    bool operator<=(const Fixed& other) const { return _value <= other._value; }
    bool operator==(const Fixed& other) const { return _value == other._value; }
    bool operator!=(const Fixed& other) const { return _value != other._value; }

    // ---------------- Arithmetic Operators ----------------
    Fixed operator+(const Fixed& other) const { return Fixed(this->toFloat() + other.toFloat()); }
    Fixed operator-(const Fixed& other) const { return Fixed(this->toFloat() - other.toFloat()); }
    Fixed operator*(const Fixed& other) const { return Fixed(this->toFloat() * other.toFloat()); }
    Fixed operator/(const Fixed& other) const { return Fixed(this->toFloat() / other.toFloat()); }

    // ---------------- Increment / Decrement ----------------
    // pre-increment
    Fixed& operator++() { _value += 1; return *this; }
    // post-increment
    Fixed operator++(int) { Fixed temp(*this); _value += 1; return temp; }
    // pre-decrement
    Fixed& operator--() { _value -= 1; return *this; }
    // post-decrement
    Fixed operator--(int) { Fixed temp(*this); _value -= 1; return temp; }

    // ---------------- Stream operator ----------------
    friend std::ostream& operator<<(std::ostream& os, const Fixed& f)
    {
        os << f.toFloat();
        return os;
    }
};

// ---------------- Main for testing ----------------
int main()
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;      // 0
    std::cout << ++a << std::endl;    // pre-increment
    std::cout << a << std::endl;      // same value
    std::cout << a++ << std::endl;    // post-increment
    std::cout << a << std::endl;      // incremented value
    std::cout << b << std::endl;      // 10.101
    return 0;
}
