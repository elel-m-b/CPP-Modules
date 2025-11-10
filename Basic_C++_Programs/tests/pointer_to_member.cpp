/*
    A pointer to member is different from a normal pointer. 
    It points to a member variable or member function of a class, 
    not to a memory address directly.
*/

#include <iostream>

class Car
{
    public:
    int speed;
};

int main()
{
    int Car::*pSpeed = &Car::speed;

    Car c1;
    c1.speed = 1;       // direct access
    std::cout << "speed is " << c1.speed << std::endl;
    c1.*pSpeed = 2;     // access via pointer to member
    std::cout << "speed is " << c1.speed << std::endl;
    return 0;
}
   