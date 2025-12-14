#include <iostream>

class       Fixed
{
    private:
    int     _value;
    static const int integer;
    public:
    Fixed()
    {
        std::cout << "Default constructor called\n";
        _value = 0;
    }
    Fixed(const     Fixed& other) // A copy constructor.
    {
        std::cout << "copy constracteur called\n";
        _value = other._value;
    }

    Fixed& operator=(const Fixed& other)
    {
        std::cout << "Copy assignment operator called \n";
        this->_value = other._value;
        return *this;
    }
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    ~Fixed(){std::cout << "Destructor called\n";}
};

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called\n";
    return (_value);
}

void    Fixed::setRawBits(int const raw)
{
    _value = raw;
}

int main( void ) 
{
    Fixed a;
    Fixed b( a );
    Fixed c;
    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}