
/*
    Memory allocation is about reserving memory for your program’s variables or objects. There are two main types:
    1 - stack allocation.
    2 - Heap allocation.
*/
   
/*
    1 - stack allocation
   . Happen automaticly
   . Memory is freed when the variable goes out of scope.
   . Fast but limited size
*/
  
// int main()
// {
//     int     a;
//     a = 10;
//     std::cout << a << std::endl;
//     return 0;
// }

/*
    2 - Heap allocation
     .happen manualy using new and free using delete
     . Usefel when you don't know size at compile time
     . you must free it manualy
*/
    
#include <iostream>
int main()
{
    int     *p = new int(50);
    std::cout << *p << std::endl;
    delete p;
    return (0);
}