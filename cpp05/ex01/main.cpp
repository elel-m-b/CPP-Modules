#include "Bureaucrat.hpp"
#include "Form.hpp"
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
    std::cout << "=== FORM CONSTRUCTION TEST ===" << std::endl;
	try
	{
		Form f1("Tax Form", 50, 25);
		std::cout << f1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== INVALID FORM GRADES TEST ===" << std::endl;
	try
	{
		Form badForm("Invalid", 0, 200);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== SIGNING SUCCESS TEST ===" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		Form topSecret("Top Secret", 10, 5);

		std::cout << topSecret << std::endl;
		boss.signForm(topSecret);
		std::cout << topSecret << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== SIGNING FAILURE TEST ===" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 150);
		Form important("Important", 10, 5);

		intern.signForm(important);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

}