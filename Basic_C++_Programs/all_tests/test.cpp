#include <iostream>

class       Test
{
    private:
    static  int a ;
    int count;
    public:

    Test() 
    {
        // a = 11;
    }
    void        add();
    void        mul();
};

void        Test::add()
{
    // a++;
    std::cout << "add "<< a << std::endl;
}
int     Test::a = 11;

void    Test::mul()
{
    std::cout << "mul " << a << std::endl;
}
int main()
{

    Test        c1;
    c1.add();
    c1.mul();
}