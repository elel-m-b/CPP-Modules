#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;

    public:
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        // Getters
        const std::string& getName() const;
        int getGrade() const;

        // Grade manipulation
        void incrementGrade();
        void decrementGrade();

        // Exceptions
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what();
        };
};

// Operator <<
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
