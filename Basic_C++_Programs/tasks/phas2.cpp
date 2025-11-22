#include <iostream>

// What is a constructor?
// A constructor is a special function that is automatically called when an object is created.
// Its job is to initialize the data (attributes) of the class.

// What is a default constructor?
// A default constructor is a constructor with no parameters.
// ⚠️ Important: It DOES NOT automatically initialize values to 0.
// If you want values to be 0, YOU must set them inside the constructor.

// What is a constructor with parameters?
// It is a normal constructor that takes arguments, like:
// ClassName(int a, int b);
// It allows you to initialize the object with specific values.

// What is a destructor?
// A destructor is a special function that is automatically called when an object is destroyed.
// It is used to clean resources (like memory created with new).
// How does the compiler know when to call it?
// → When the object goes out of scope OR when you delete a dynamically allocated object.

// Example 1: Default constructor

// class Test
// {
// private:
//     int a;
//     int b;
// public:
//     Test()  // default constructor
//     {
//         a = 0;
//         b = 0;
//         std::cout << "Object created\n";
//     }
//     ~Test() // destructor
//     {
//         std::cout << "Object destroyed\n";
//     }
// };

// int main()
// {
//     Test c1; // constructor runs automatically
// }           // end of scope → destructor runs automatically



// Example 2: Constructor with parameters

class Test
{
private:
    int a;
    int b;

public:
    Test(int m, int n) // constructor with parameters
    {
        a = m;
        b = n;
        std::cout << "Object created with parameters\n";
    }

    ~Test() // destructor
    {
        std::cout << "Object destroyed\n";
    }
};

int main()
{
    Test c1(1, 2);  // ✅ Correct way to create an object
                    // ❌ Wrong: Test::Test(1,2) does NOT create an object
}
