#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form 
{
    private:
    const std::string name;
    bool isSigned;
    public:
        Form();
        Form(const Form& other);
        Form&   operator=(const Form& other);
        ~Form();
};

#endif