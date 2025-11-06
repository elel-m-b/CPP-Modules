#include <iostream>



class Car 
{
public:
    std::string model;
    int speed;

    Car(std::string m, int s) 
    {
        model = m;
        speed = s;
    }

    void accelerate(int amount) 
    {
        speed += amount;
        std::cout << model << " now going " << speed << " km/h\n";
    }
};

int main() 
{
    Car     t;
    t.accelerate(100);
}
