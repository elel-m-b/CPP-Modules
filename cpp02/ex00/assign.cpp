// copy assignement operateur
#include <iostream>
class       Fixed
{
    private:
    int     value;

    public:
    int     x;
    Fixed() : value(0) {}

    Fixed(const Fixed &other)
    {
        value = other.value;
        std::cout  << "copy constracteur are called\n";
    }
    Fixed& operator=(const  Fixed &other)
    {
        std::cout << "Copy Assignment Operator called" << std::endl;
        if (this != &other)
        {
            std::cout << "ok\n";
            value = other.value;
        }
        return (*this);
    }
    void    setValue(int v) {value = v;}
    int getValue() {return value;}
};

int main()
{
    Fixed   a;
    a.setValue(42);
    Fixed       b;
    b = b;
    std::cout << "b = " << b.getValue() << "\n";

    Fixed       c = a;
    std::cout << "c = " << c.getValue() << "\n";
}