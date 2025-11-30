#include <iostream>


class       Harl
{
    private:

    void        debug();
    void        info();
    void        warning();
    void        error();

    public:
    void        complain(std::string level);
};

void        Harl::complain(std::string      level)
{
    std::string     levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    std::cout << levels[3];
}

int main()
{
    Harl        c1;

}