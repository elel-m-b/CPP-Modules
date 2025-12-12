#include <iostream>
// operateur overloding
class       Test
{
    public:
    int     x;
    Test(int a): x(a) {}

    Test        operator*(const Test    &other)
    {
        return Test(x * other.x);
    }
};

int main()
{
    Test    a(10);
    Test    b(11);
    Test    c = a * b ;
    std::cout << c.x << "\n";
}