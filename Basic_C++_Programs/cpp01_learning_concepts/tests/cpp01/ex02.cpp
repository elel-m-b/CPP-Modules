#include <iostream>


void        ft_ft(int &ref)
{
    ref = 2;
    std::cout << "ref addr in function: " << &ref << "\n";
    
}

int main()
{
    int         x = 1;
    int &ref = x;
    std::cout << "x addr: " << &x << "\n";
    std::cout << "ref addr: " << &ref << "\n";
    ft_ft(x);
}