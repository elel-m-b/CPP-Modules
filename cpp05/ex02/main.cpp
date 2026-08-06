#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "====test1 : Execute before signing=====\n";
	try{
		Bureaucrat lmodir("lmodir", 1);
		ShrubberyCreationForm form("test");
		lmodir.executeForm(form);
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}

    std::cout << "\n=====test2 :Sign and Execute ===\n";
    try
    {
        Bureaucrat boss("Boss", 1);
        ShrubberyCreationForm form("home");
        boss.signForm(form);
        boss.executeForm(form);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}