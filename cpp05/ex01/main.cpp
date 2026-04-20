#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat bob("Bob", 50);
        Form formA("FormA", 30, 10);

        std::cout << bob << std::endl;
        std::cout << formA << std::endl;

        bob.signForm(formA);

        Bureaucrat boss("Boss", 1);
        boss.signForm(formA);

        std::cout << formA << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}