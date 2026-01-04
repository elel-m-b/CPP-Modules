#include <iostream>

class       Test
{
    public:
    int v;
    int     *x = new int(42);
    Test(int val );
    Test(Test& other);
    Test&       operator=(Test&     other);
    std::ostream&   operator<<(std::ostream& f);
    Test   operator+(Test& other);
    bool        operator<(Test& other);
    static const Test &min(const Test &a, const Test &b);
    ~Test();
};

Test::Test(int val) : v(val) {}

// std::ostream&   operator<<(std::ostream& f, Test &d)
// {
//     f << d.v;
//     return f;
// }
bool Test::operator<(Test& other)
{
    if (this->v < other.v)
        return (true);
    return (false);
}

Test        Test::operator+(Test& other)
{
    return Test((other.v + this->v));
}

std::ostream&       Test::operator<<(std::ostream &f)
{
    f << this->v;
    return f;
}

Test::Test(Test& other)
{
    std::cout << "copy are called\n";
    *this = other;
}

Test& Test::operator=(Test& other)
{
    std::cout << "asignemt are called\n";
    if (this != &other)
        this->x = new int(42);
    return *this;
}

Test::~Test()
{
    delete x;
    std::cout << "Destroyed\n";
}

int main()
{
    Test        c1(1);
    Test        c2(2);
    c1 << std::cout << "\n";
    Test    c3 = c1 + c2;
    Test(10);
    c3 << std::cout << "\n";
}