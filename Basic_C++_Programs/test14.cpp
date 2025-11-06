//Namespaces

#include <iostream>
// namespace MyNamespace 
// {
//     int value = 42;
//     void printMessage() 
//     {
//         std::cout << "Hello from MyNamespace!" << std::endl;
//     }
// }

// // Usage
// int main() {
//     std::cout << MyNamespace::value << std::endl;
//     MyNamespace::printMessage();
// }

// namespace Math 
// {
//     int add(int a, int b) { return a + b; }
//     int subtract(int a, int b) { return a - b; }
// }

// int main() 
// {
//     using Math::add;
//     std::cout << add(5, 3) << std::endl; // Works
//     // std::cout << subtract(5, 3); // Error! Not imported
    
//     // Using directive - imports all names
//     using namespace Math;
//     std::cout << subtract(5, 3) << std::endl; // Now works
// }

// namespace Company 
// {
//     int a;
//     namespace Engineering 
//     {
//         int     b;
//         namespace Backend 
//         {
//             int         c;
//             void deploy() 
//             {
//                 std::cout << "Deploying backend..." << std::endl;
//             }
//         }
//     }
// }

// int main() {
//     // C++17 style
//     Company::Engineering::Backend::deploy();
//     Company::Engineering::b = 1;
//     std::cout << Company::Engineering::b << std::endl;
//     // With alias
//     namespace Backend = Company::Engineering::Backend;
//     Backend::deploy();
// }

// file1.cpp
namespace 
{
    int secret = 100; // Internal linkage - only visible in this file
}

void printSecret() 
{
    std::cout << secret << std::endl;
}


namespace
{
    int secret = 200; // Different variable, no conflict!
}

int main()
{
    printSecret();
}