#include <iostream>

class       Test
{
    public:
    int  x;
    // Test();
    Test(int val);
    Test(const Test& other);
    ~Test();
    Test&   operator=(const Test& other);
};


class   child : public  Test
{
    public:
    int     y;
    // child();
    child(int val);
    child(const child& other);
    ~child();
    child&   operator=(const child& other);
};

//parent

// Test::Test()
// {
//     std::cout << "Default constracteur of parent are called\n";
// }

Test::Test(int val) : x(val)
{
    std::cout << "Constarcteur called\n";
}

Test::Test(const Test& other)
{
    *this = other;
}

Test::~Test()
{
    std::cout << "Destarcteur are called\n";
}

Test&       Test::operator=(const Test& other)
{
    std::cout << "Copy assignment operatore from parent are called\n";
    if (this != &other)
    {
        x = other.x;
    }
    return *this;
}

// child

// child::child()
// {
//     std::cout << "Default constracteur from child are called\n";
// }

child::child (int val) : y(val)
{
    std::cout << "Constarcteur from child called\n";
}

child::child(const child& other): Test(other)
{
    *this = other;
}

child::~child()
{
    std::cout << "Destarcteur from child are called\n";
}

child&       child::operator=(const child& other)
{
    std::cout << "Copy assignment operatore from child are called\n";
    if (this != &other)
    {
        x = other.x;
    }
    return *this;
}

int main()
{
    // child t(42);
}