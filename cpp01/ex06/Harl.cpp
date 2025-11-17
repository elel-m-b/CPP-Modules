#include "Harl.hpp"
#include <iostream>

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug() 
{
    std::cout << "[ DEBUG ]\n"
              << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n" << std::endl;
}

void Harl::info() 
{
    std::cout << "[ INFO ]\n"
              << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning() 
{
    std::cout << "[ WARNING ]\n"
              << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n" << std::endl;
}

void Harl::error() 
{
    std::cout << "[ ERROR ]\n"
              << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain(std::string level) 
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*functions[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (int i = 0; i < 4; ++i) 
    {
        if (levels[i] == level) 
        {
            (this->*functions[i])();
            return;
        }
    }

    // Default message for unknown levels
    std::cout << "[ Probably complaining about insignificant problems ]\n"
              << "Although there are several ways to deal with Harl, one of the most effective is to SWITCH it off.\n" << std::endl;
}

// This prints all messages from given level and above
void Harl::complainFromLevel(int level) 
{
    switch (level) 
    {
        case 0:
            debug();
            // fallthrough
        case 1: // INFO
            info();
            // fallthrough
        case 2: // WARNING
            warning();
            // fallthrough
        case 3: // ERROR
            error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n"
                      << "Although there are several ways to deal with Harl, one of the most effective is to SWITCH it off.\n" << std::endl;
            break;
    }
}
