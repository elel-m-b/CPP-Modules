#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(const std::string& formName, const std::string& target);

private:
    typedef AForm* (*FormCreator)(const std::string& target);

    static AForm* createShrubbery(const std::string& target);
    static AForm* createRobotomy(const std::string& target);
    static AForm* createPresidential(const std::string& target);
};

#endif