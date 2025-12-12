#include <iostream>


class       Fixed
{
    private:
    int     _value;
    public:
    Fixed()
    {
        _value = 0;
    }
    Fixed(const     Fixed& other) // A copy constructor.
    {
        std::cout << "are called";
        _value = other._value;
    }

    Fixed& operator=(const Fixed& other)
    {
        if (this != &other )
        {
            _value = other._value;
        }
        return *this;
    }
    ~Fixed(){}
};


int main()
{
    Fixed a;
    Fixed b(a);
}