#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& n, int s, int e)
	: _name(n), _isSigned(false), _gradeToSign(s), _gradeToExecute(e)
{
	if (s < 1 || e < 1) throw GradeTooHighException();
	if (s > 150 || e > 150) throw GradeTooLowException();
}

AForm::~AForm() {}

std::string AForm::getName() const { return _name; }
bool AForm::getIsSigned() const { return _isSigned; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExecute() const { return _gradeToExecute; }

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= _gradeToSign) _isSigned = true;
	else throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!_isSigned) throw NotSignedException();
	if (executor.getGrade() > _gradeToExecute) throw GradeTooLowException();
	executeAction();
}

const char* AForm::GradeTooHighException::what() const throw()
{ return "Grade too high"; }

const char* AForm::GradeTooLowException::what() const throw()
{ return "Grade too low"; }

const char* AForm::NotSignedException::what() const throw()
{ return "Form not signed"; }

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	return os << f.getName() << " signed: " << f.getIsSigned();
}