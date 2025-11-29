#include <iostream>
#include <string>

class Test
{
    private:
    std::string name;

    public:
    char change(char c)
    {
        if (c >= 'a' && c <= 'z')
            return c - 32;
        return c;
    }

    Test()
    {
        name = "Hello world";
        std::cout << "[Constructor] Test object created at address: " << this << std::endl;
    }

    ~Test()
    {
        std::cout << "[Destructor] Test object destroyed at address: " << this << std::endl;
    }

    std::string getName()
    {
        return name;
    }

    std::string onstack(std::string name);
    std::string onheap(std::string name);
};

std::string Test::onstack(std::string name)
{
    Test c1; // STACK allocation
    std::cout << ">> STACK object address: " << &c1 << std::endl;

    name = c1.getName();
    std::cout << "Name before (stack): " << name << std::endl;

    for (int i = 0; i < name.length(); i++)
        name[i] = c1.change(name[i]);

    std::cout << "<< STACK object will be destroyed when leaving this function.\n";

    return name;
}

std::string Test::onheap(std::string name)
{
    Test* c2 = new Test(); // HEAP allocation
    std::cout << ">> HEAP object address: " << c2 << std::endl;

    name = c2->getName();
    std::cout << "Name before (heap): " << name << std::endl;

    for (int i = 0; i < name.length(); i++)
        name[i] = c2->change(name[i]);

    std::cout << "<< HEAP object must be destroyed manually using delete.\n";

    // delete c2; // manual destruction (important!)
    return name;
}

int main()
{
    std::string name;
    Test c1;

    std::cout << "\n===== STACK TEST =====\n";
    name = c1.onstack(name);
    std::cout << "On stack (result): " << name << "\n";

    std::cout << "\n===== HEAP TEST =====\n";
    name = c1.onheap(name);
    std::cout << "On heap (result): " << name << "\n";

    return 0;
}
