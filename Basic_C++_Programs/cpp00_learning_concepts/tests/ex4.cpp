#include <iostream>

class       Car
{
    private:
    int     brand;
    int     year;
    public:
    void        Setyear(int a)
    {
        year = a;
        year++;
    }
    
    int     getyear()
    {
        return (year);
    }
};

int main()
{
    Car     c1;
    c1.Setyear(11);
    int     x = c1.getyear();
    std::cout << x;
}