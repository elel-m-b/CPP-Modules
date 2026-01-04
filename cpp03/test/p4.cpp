#include <iostream>
int m;
class       Test
{
    private:
    std::string name;
    public:
    int b;
    Test(int val);
    ~Test();
};


class   child : public Test
{
    public:
    int c;
    child(int a);
    ~child();
};

Test::Test(int val) : b(val)
{
    std::cout << "Constarcteur are called\n";
}

Test::~Test()
{
    std::cout << "Destracteur are called\n";
}

child::child(int a): Test(a)
{
    std::cout << "child constarcteur are called\n";
}

child::~child()
{
    std::cout << "Child destracteur are called\n";
}

int main()
{
    // Test        c1;
}