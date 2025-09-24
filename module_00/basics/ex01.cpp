#include <iostream>
// class       test
// {
//     int     a;
//     public:
//         int     a;
//     private:
//         int     a;
// };

// namespace a
// {
//     int     x = 9;
//     int a = 1;

// }
// namespace       b
// {
//     int         x = 10;
//     int a = 1;
// }

// int main()
// {
//     std::cout << a::x<<std::endl;
//     std::cout << b::x<<std::endl;
//     std::cout << a::a;
//     test    a;
//     return (0);
// }

// std “standard” namespace. 
// :: (Scope Resolution Operator)  (:: tells the compiler where to find something )
// cout = “character output stream”. It sends data to the console (terminal).

// << (Insertion Operator) end this into the output stream
// iostream
// namespace a
// {
//     int     test()
//     {
//         return (111);
//     }
// }

// namespace b
// {
//     int     test()
//     {
//         return (12);
//     }
//     int     x;
// }

// int main()
// {
//     std::cout << a::test() << std::endl;
//     b::x = 10;
//     std::cout <<  b::x;
// }


// int main()
// {
//     std::cout << "Enter x : ";
//     int     x;
//     std::cin >> x;
//     std::cout << "your age are " << x << "\n" ;
// }

// what is a stream  ?? <iostream>

// class   test
// {
//     public:
//         int     x; // attribute
//     private:
//         void    function(int c); // we create a methode
// };

// int main()
// {
//     test        a;   // we creat an object
//     a.function(1);
// }

// pointer to object + create an array of objects

// class       test
// {
//     public:
//         int     a;
//         void        test_me(int x)
//         {
//             std::cout << "The value of x is" << "  " << x;
//         }
// };

// int main()
// {
//     test        *p = new test;
//     p->a = 1;
//     p->test_me(10);
//     delete      p;
//     return (0);
// }
// Access Specifiers in C++?

class test
{
    public:
        int     x;
    void        display()
    {
        std::cout << "th value of x is " << x << "\n";
    }
    private:
        int     sec;
    public:
        void    setSec(int      val)
        {
            sec = val;
            // std::cout << val;
            // std::cout << "the value is " << sec;
        }
        int     getSec()
        {
            return (sec);
        }
};

int main()
{
    std::cout.rdbuf()->~basic_streambuf();
    test        a;
    a.x = 100;
    a.display();
    a.setSec(10);
    int     c = a.getSec();
    std::cout << c;
}