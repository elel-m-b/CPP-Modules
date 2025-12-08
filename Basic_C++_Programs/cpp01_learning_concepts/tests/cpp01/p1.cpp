#include <iostream>



int main()
{
    std::string     s1 = "Hello world";
    std::string s2 = s1.substr(0, 10);
    std::cout << "s2 == " << s2;
}