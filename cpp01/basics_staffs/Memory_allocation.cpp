#include <iostream>
#include <cstring>

// test 1

// int main ()
// {
    // int a = 10;          
    // int *p = new int(20);
    // delete p;
    // std::cout << a + *p;
// }

// test 2

// int main ()
// {
    // int a = 10;          
    // int *p = new int(20);
    // std::cout << a + *p;
    // delete p;
// }


// test 3

// int main ()
// {
    // int *arr = new int[3]{1, 2, 3};
    // std::cout << arr[0] + arr[2];
    // delete[] arr;
// }
 
// test 4

// int main()
// {
    // char        *name;
    // char        *name = new         char[20];
    // strcpy(name, "Hello world");
    // std::cout << name;
// }

// test 5


int main()
{
    std::string *ptr = new std::string("World");
    std::cout << *ptr;
    delete ptr;
}