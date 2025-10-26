#include <iostream>

namespace very_long_namespace_name 
{
    struct Point { int x, y; };
    void process(const Point& p)
    {
        std::cout << "x== " << p.x << "y== " << p.y << std::endl;
    }
}

namespace A 
{
    namespace B 
    {
        class Widget 
        {
        public:
            void foo()
            {
                std::cout << "Hello world" << std::endl;
            }
        };
    }
}

// What are three different ways to access Widget::foo()?
// How does Argument Dependent Lookup (ADL) work with the Point example?
int main()
{

    A::B::Widget    a;
    a.foo();
    very_long_namespace_name::Point     p;
    p.x = 1;
    p.y = 2;
    very_long_namespace_name::process(p);

}