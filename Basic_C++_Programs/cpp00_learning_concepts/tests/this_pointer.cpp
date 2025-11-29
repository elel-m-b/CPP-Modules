#include <iostream>

class       Test
{
    private:
    int     age;
    public:
    void    setAge(int age)
    {
        std::cout << age << std::endl;
        age = age;
    }
    int     getAge() const
    {
        return (age);
    }
};

int main()
{
    Test        c1;
    c1.setAge(10);
    int     a = c1.getAge();
    std::cout <<  a;
}