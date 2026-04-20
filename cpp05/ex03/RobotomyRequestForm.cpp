// .cpp
#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("Robotomy", 72, 45), _target(target) {}

void RobotomyRequestForm::executeAction() const
{
	std::cout << "Drilling noises...\n";
	if (rand() % 2)
		std::cout << _target << " robotomized successfully\n";
	else
		std::cout << "Robotomy failed\n";
}