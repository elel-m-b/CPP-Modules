#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
int main()
{
	Bureaucrat lomodir("lmodir", 1);
	Intern intern;

	AForm *form;

	form = intern.makeForm("shrubbery creation", "hassan");
	if (form)
	{
		lomodir.signForm(*form);
		lomodir.executeForm(*form);
		delete form;
	}
}