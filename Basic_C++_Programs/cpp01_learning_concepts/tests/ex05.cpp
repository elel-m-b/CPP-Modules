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

int main()
{
    Harl        c1;
    std::string     levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
}