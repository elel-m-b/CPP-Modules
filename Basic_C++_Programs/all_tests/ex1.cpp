#include <iostream>


namespace       MathOps
{
    int     add(int a, int b)
    {
        return (a + b);
    }
}
namespace       StringOps
{
    std::string     add(const std::string a, const std::string b)
    {
        return (a + b);
    }
}

int main()
{
    int     x = MathOps::add(1, 2);
    std::cout << x << std::endl;
    std::string str = StringOps::add("Hello", "World");
    std::cout << "result " << str << std::endl;

}