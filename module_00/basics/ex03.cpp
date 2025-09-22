#include <iostream>
#include <iomanip> 
// class math_lib
// {
//     public:
//     void print();
// };

// class   logger_lib
// {
//     public:
//     void print();
// };

// void math_lib::print()
// {
//     std::cout << "Hello from math lib\n";
// }

// void    logger_lib::print()
// {
//     std::cout << "Hello form logger lib\n";
// }

// int main()
// {
//     math_lib        t1;
//     logger_lib      t2;

// }

// namespace ha
// {
//     void      print()
//     {
//         std::cout << "Hello 1";
//     }
// };

// namespace ho
// {
//     void      print()
//     {
//         std::cout << "Hello 1";
//     }
// };

// int main()
// {
//     ha::print();
//     ho::print();
// }


// int main()
// {
//     std::string name = "Hassan";



//     if (name.length() > 10)
//         name = name.substr(0, 9) + '.';
//     // std::cout << "new string is: " << name;
//     std::cout << "|" << name;
//     for (int i = name.length(); i < 10; i++)
//         std::cout << " ";
//     std::cout << "|" << std::endl;
// }


int main()
{
    std::cout << "|" << std::setw(10) << "HA";
}