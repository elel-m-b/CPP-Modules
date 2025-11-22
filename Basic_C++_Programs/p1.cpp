#include <iostream>

class   Car
{
    public:
    int     speed;
};

int main()
{
    int Car::*pSpeed = &Car::speed;
    Car     c1;
    c1.*pSpeed = 100; 
    c1.speed =  1;
    std::cout << "speed is " << c1.speed << std::endl;
    c1.speed =  10;
    std::cout << "speed is " << c1.speed << std::endl;
}