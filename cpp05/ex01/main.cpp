#include "Bureaucrat.hpp"



int main(void)
{
    try
    {
        Bureaucrat b("Ahmed", -1);   
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try 
    {
        Bureaucrat b("Hassan", 150);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << Bureaucrat("Ahmed", 1) << std::endl;
    Bureaucrat b("Hassan", 150);
    std::cout << Bureaucrat("Hasaan", 150) << std::endl;


    // int a;
    // std::cin >> a;
    // try 
    // {
    //     if (a < 0)
    //         throw   std::invalid_argument("Error");
    // }
    // catch (std::exception& e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
}