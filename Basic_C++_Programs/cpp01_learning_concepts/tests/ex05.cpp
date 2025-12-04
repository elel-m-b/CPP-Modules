#include <iostream>

class       Harl
{
    private:
    void        debug();
    void        info();
    void        warning();
    void        error();
    public:
    void        complain(std::string        level);
};

void        Harl::debug()
{
    std::cout << "Debug meesage" << "\n";
}

void        Harl::info()
{
    std::cout << "Info message" << "\n";
}

void        Harl::warning()
{
    std::cout  << "Warning message" << "\n";
}
void    Harl::error()
{
    std::cout << "Error message" << "\n";
}

// return_type (ClassName::*pointer_name)(argument_types) = &ClassName::member_function;

void        Harl::complain(std::string level)
{
    std::string     levels[] = {"DUBUG", "INFO", "WARNING", "ERROR"};
    void        (Harl::*pointer[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            (this->*pointer[i])();
            return;
        }
    }
    std::cout << "Unknow level\n";
}

int main(void)
{
    Harl   c1;
    c1.complain("DUBUG");
}