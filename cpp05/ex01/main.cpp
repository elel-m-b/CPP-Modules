#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat lmodir("lomodir", 1);
    try{
        Form a;
        Form b("test1", 1, 1);
        b.beSigned(lmodir);
        // std::cout << b.getIsSigned() << std::endl;
        std::cout << b << std::endl;
        std::cout << a << std::endl;
        lmodir.signForm(b);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}