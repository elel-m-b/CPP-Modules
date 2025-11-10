/*
    Purpose: Group data (variables) and behavior (functions) into a single unit (object).
*/

#include <iostream>

class       Car 
{
    public:
    std::string     brand;
    void    honl() {std::cout << "my car is" << brand << std::endl; }
};

int main()
{
    Car my_car; // create object
    my_car.brand = "dacia";
    my_car.honl();
}