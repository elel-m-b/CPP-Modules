#include <iostream>


class Test
{
    public:
    std::string name;
    Test(std::string n);
    ~Test();
};

class child : public Test
{
    public:
    std::string name;
    child(std::string n);
    ~child();
};

Test::Test(std::string n) : name(n)
{
    std::cout << "parent constracteur are called\n";
}

Test::~Test()
{
    std::cout << "parent destracteur are called\n";
}

child::~child()
{
    std::cout << "child destracteur are called\n";
}

child::child(std::string n) : Test(n) ,name(n)
{
    std::cout << "child constracteur are called\n";
}


int main(void)
{
    child       c1("P1");
    Test        c2("P2");
    std::cout << c1.name << std::endl;
    std::cout << c2.name << std::endl;
}