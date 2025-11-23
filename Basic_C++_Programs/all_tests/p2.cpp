#include <iostream>

class   Test
{
    public:
    int         age;
    int     tol;
    void        greet()
    {
        std::cout << "Hello from greet()\n";
    }
    void        jump()
    {
        std::cout << "Hello from Jump\n";
    }
};

int main()
{
    Test        c1;
    c1.age = 21;
    c1.tol = 160;

    int     Test:: *ptr = &Test::age; // pointer to data member
    std::cout << c1.*ptr + 1 << "\n";
    Test    *p = &c1;
    std::cout << p->*ptr << "\n";
    (*p).age = 11;
    std::cout << "new valeur " << c1.age << "\n";

    void (Test::*f_ptr)() = &Test::greet; // pointer to member function
    (c1.*f_ptr)();
    p->greet();
    (*p).greet();
}