#include <iostream>


// namespace       test1
// {
//     int     add(int a, int b)
//     {
//         return (a + b);
//     }
// }
// namespace   test2
// {
//     int     add(int a, int b)
//     {
//         return (a + b);
//     }
// }

// int main()
// {
//     int n1 = test1::add(1,2);
//     int n2 = test2::add(1,2);
//     std::cout << n1 << "\n";
//     std::cout << n2;
//     return (0);
// }

// 🔹 1. Constructors (basic idea)
// class       test
// {
//     public:
//     int     age;
//     std::string name;


//     // constructor
//     test()
//     {
//         std::cout << "Hello" << std::endl;
//         name = "Hassan";
//         age = 12;
//     }
//     void print()
//     {
//         std::cout << "Hi I am " << name << " my age is " << age << std::endl;
//     }
// };

// int main()
// {
//     test        m;
//     std::cout << m.age << std::endl;
//     // m.print();
// }

// class test
// {
//     public:
//     int     a;
//     int     b;
// };
// int main()
// {
//     test  a;
//     a.a = 1;
//     a.b = 2;
//     test        b;
//     b = a;
//     std::cout << b.a << "\n";
//     std::cout << b.b << "\n";
// }

//🔹 2. Destructors (basic idea)

class test
{
    public:
    std::string name;
    test()
    {
        std::cout << name << " created.\n";
    }
    ~test()
    {
        std::cout << name << " destroyed.\n";
    }
};

int main()
{
    test        a;
}