#include <iostream>

// 1 - shallow copy
// class       Test
// {
//     public:
//     int     *x;
//     int     b;
// };

// int main()
// {
//     Test    obj1;
//     obj1.x = new int (42);
//     Test        obj2 = obj1; // shallow copy
//     *obj1.x = 11;
//     std::cout << obj2.x << "\n"; // the some address
//     std::cout << obj1.x << "\n";
//     std::cout << &obj1.b << "\n";
//     std::cout << &obj2.b << "\n";
//     obj2.b = 11;
//     std::cout << obj1.b << "\n";
//     std::cout << obj2.b << "\n";
// }

// 2 - deep copy
#include <iostream>
using namespace std;

class MyClass {

    public:
    int value;
    MyClass(){}

    // Copy constructor WITHOUT reference
 MyClass(const MyClass &source) { 
    value = source.value; 
}

};
int main() {
    MyClass obj1;
    obj1.value = 10;

    cout << "Creating obj2..." << endl;
    MyClass obj2 = obj1; // هنا كيتستدعى copy constructor بلا &
    
    cout << "obj2.value = " << obj2.value << endl;
    return 0;
}
