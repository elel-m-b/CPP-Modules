#include <iostream>
#include <string>




int main()
{
    std::string     str = "HI THIS IS BRAIN";
    std::string     *stringPtr = &str;
    std::string &string_ref = str;

    std::cout << "Addresses: " << std::endl;
    std::cout << &str << std::endl;
    std::cout << stringPtr << std::endl;
    std::cout << &string_ref << std::endl;

    std::cout << "\nValues:" << std::endl;
    std::cout << str << std::endl;
    std::cout << *stringPtr << std::endl;
    std::cout << string_ref << std::endl;
    
    return (0);
}