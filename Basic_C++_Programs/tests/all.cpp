#include <iostream>


class       Test
{
    private:
    std::string name;
    public:
    int     x;
    int     y;
    void    print(void)
    {
        std::cout  << "Hello world\n";
    }
    Test()
    {
        int     a = 1;
        x = a;
        std::cout  << "Constracteur called\n";
    }
    ~Test()
    {
        std::cout << "Destracteur are called\n";
    }
};

int main()
{
    Test        c1;
    std::cout << c1.x << std::endl;
}