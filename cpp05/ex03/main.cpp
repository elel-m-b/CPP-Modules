#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat boss("Boss", 1);

	ShrubberyCreationForm s("home");
	RobotomyRequestForm r("Bender");
	PresidentialPardonForm p("Arthur");

	boss.signForm(s);
	boss.executeForm(s);

	boss.signForm(r);
	boss.executeForm(r);

	boss.signForm(p);
	boss.executeForm(p);
}