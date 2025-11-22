#include <iostream>

// ==========================================================
// INITIALIZATION LIST (Initializer List)
// ----------------------------------------------------------
// What is an initialization list?
// It is a special C++ syntax used to initialize the members
// of a class BEFORE the constructor body runs.
//
// Example:
// Test() : a(10), b(11) {}
//
// The values are assigned directly during object creation.
// ==========================================================


// ==========================================================
// DIFFERENCE BETWEEN:
// 1) Constructor body
// 2) Initialization list
// 3) Setters
// ----------------------------------------------------------
//
// (1) CONSTRUCTOR BODY:
//     Runs AFTER the initialization list.
//     Good for logic, checks, printing messages.
//     NOT good for initializing complex members.
//
// (2) INITIALIZATION LIST:
//     Best way to initialize class members.
//     Especially required for:
//        - const variables
//        - references
//        - classes without default constructor
//     Faster & more efficient.
//
// (3) SETTERS:
//     Normal functions used to MODIFY values AFTER the object
//     is created.
//     Example: setA(5), setName("John")
// ----------------------------------------------------------
//
// WHEN DO WE USE EACH ONE?
// ----------------------------------------------------------
// ✔ Use INITIALIZATION LIST:
//      - when initializing const or reference variables
//      - when a variable has no default constructor
//      - when you want faster initialization
//
// ✔ Use CONSTRUCTOR BODY:
//      - when you want to run logic AFTER initialization
//      - printing, conditions, calculations
//
// ✔ Use SETTERS:
//      - when changing values after object creation
//      - when you need validation (ex: age > 0)
// ==========================================================

// syntax of inisialization list

/*
class Test
{
private:
    int a;
    int b;

public:
    // Correct syntax of constructor with initialization list:
    Test() : a(10), b(11)
    {
        std::cout << "Constructor body runs after initialization.\n";
    }
};


int main()
{
    Test c1;
}
*/

// 1️⃣ Initialization List

// Use it for const, reference, or classes without default constructor, or for efficiency.

// - > example

/*
class ExampleInitList
{
    private:
    const int x;         // const → must be initialized here
    int &y;              // reference → must be initialized here
    std::string name;    // string has default constructor but we can initialize directly

    public:
    // Constructor with initialization list
    ExampleInitList(int a, int &b, std::string n) : x(a), y(b), name(n)
    {
        std::cout << "Initialization list used.\n";
    }

    void show() const
    {
        std::cout << "x = " << x << ", y = " << y << ", name = " << name << "\n";
    }
};

int main()
{
    int value = 50;
    ExampleInitList obj(10, value, "Ali");
    obj.show();
}
*/

// 2️⃣ Constructor Body

// Use it when you want logic to run after initialization, like calculations, conditions, printing messages.

/*
class ExampleConstructorBody
{
    private:
    int a;
    int b;

    public:
    ExampleConstructorBody(int x, int y)  // members initialized to garbage here
    {
        // Logic after initialization
        if (x > y)
        {
            a = x;
            b = y;
        }
        else
        {
            a = y;
            b = x;
        }

        std::cout << "Constructor body ran logic after initialization\n";
    }

    void show() const
    {
        std::cout << "a = " << a << ", b = " << b << "\n";
    }
};

int main()
{
    ExampleConstructorBody obj(5, 10);
    obj.show();
}
*/


// 3️⃣ Setters 

// Use setters after object creation, usually for validation or changing values dynamically.


/*


class ExampleSetter
{
    private:
    int age;

    public:
    ExampleSetter() : age(0) {}  // default initialization

    // Setter with validation
    void setAge(int a)
    {
        if (a >= 0)
            age = a;
        else
            std::cout << "Invalid age!\n";
    }

    int getAge() const { return age; }
};

int main()
{
    ExampleSetter obj;
    obj.setAge(25);       // valid
    std::cout << "Age = " << obj.getAge() << "\n";

    obj.setAge(-10);      // invalid
    std::cout << "Age = " << obj.getAge() << "\n";
}

*/

/*
✅ Explanation:

Setters allow you to change values after the object is created

You can add validation logic (ex: age ≥ 0)

They cannot be const or reference members initialized after creation
*/