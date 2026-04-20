#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;

public:
	AForm(const std::string& name, int sign, int exec);
	virtual ~AForm();

	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(const Bureaucrat& b);

	void execute(Bureaucrat const & executor) const;

	virtual void executeAction() const = 0;

	class GradeTooHighException : public std::exception {
		public: const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public: const char* what() const throw();
	};
	class NotSignedException : public std::exception {
		public: const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif