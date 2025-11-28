#include <iostream>

class       Test
{
    private:

    std::string name;
    public:
    char        change(char c)
    {
        if (c >= 'a' && c <= 'z')
            return (c - 32);
        return (c);
    }
    Test()
    {
        name = "Hello world";
    }
    std::string     getName()
    {
        return (name);
    }

    std::string        onstack(std::string name){}
    std::string        onheap(std::string name){return name;}
};

std::string        Test::onstack(std::string name)
{
    Test        c1;

    name = c1.getName();
    std::cout << "name Before is " << name << std::endl;
    for (int        i = 0; i < name.length(); i++)
        name[i] = c1.change(name[i]);
    std::cout << "Afeter " << name;
    return (name);
}

int main()
{

    std::string         name;
    Test    c1;
    name = c1.onstack(name);
    std::cout << "On stack " << name << "\n";
    return 0;
}