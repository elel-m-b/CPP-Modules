#include <iostream>

class A {
    private:
        int c;
    public:
        A();
        A(int a);
        int operator+(int a);
};


A::A() {
    c = 0;
}

A::A(int a): c(a) {}

int A::operator+(int a)
{
    std::cout << c << std::endl;
}


int add(int a, int b)
{
    return a + b;
}

float add(float a, float b)
{
    return a + b;
}

std::string add(std::string a, std::string b) {
    return a + b;
}


int main()
{
 
    std::cout << add("Hello ", "world\n");
    std::cout << add(10, 20) << '\n';
}