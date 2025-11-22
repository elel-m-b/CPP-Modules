#include <iostream>

#include <iostream>
#include <string>

// ==================================================================
// WHAT IS "this" POINTER ?
// ------------------------------------------------------------------
// "this" is a hidden pointer available inside all non-static member functions.
// It points to the **current object** on which the member function is called.
// ==================================================================

// ==================================================================
// APPLICATIONS OF "this"
// ------------------------------------------------------------------
// 1) Disambiguate between member variables and parameters
// 2) Return current object for method chaining
// 3) Pass current object to another function
// 4) Access members via pointer
// ==================================================================

class Test
{
private:
    int a;
    int b;
    std::string name;

public:
    // ==================================================================
    // 1) DISAMBIGUATE MEMBER VARIABLES
    // If parameter name = member variable name, we use this-> to clarify
    // ==================================================================
    Test(int a, int b, std::string name)
    {
        this->a = a;      // member a = parameter a
        this->b = b;      // member b = parameter b
        this->name = name; // member name = parameter name
    }

    // ==================================================================
    // 2) METHOD CHAINING
    // We can return *this to chain multiple member function calls
    // ==================================================================
    Test &setA(int value)
    {
        this->a = value;
        return *this; // return current object by reference
    }

    Test &setB(int value)
    {
        this->b = value;
        return *this;
    }

    Test &setName(const std::string &n)
    {
        this->name = n;
        return *this;
    }

    // ==================================================================
    // 3) DISPLAY FUNCTION
    // ==================================================================
    void display() const
    {
        std::cout << "a = " << a << ", b = " << b << ", name = " << name << "\n";
    }

    // ==================================================================
    // 4) PASS CURRENT OBJECT TO ANOTHER FUNCTION
    // ==================================================================
    void passToFunction()
    {
        printObject(this); // send pointer to current object
    }

    // Static function to accept object pointer
    static void printObject(Test *obj)
    {
        std::cout << "Printing object via this pointer: ";
        obj->display();
    }

    // ==================================================================
    // 5) RETURN CURRENT OBJECT POINTER
    // Useful in some advanced patterns
    // ==================================================================
    Test *getPointer()
    {
        return this; // return pointer to current object
    }
};

int main()
{
    // Create object
    Test t1(1, 2, "Ali");
    t1.display();

    std::cout << "----------------------------------\n";

    // 2) Method chaining using this pointer
    t1.setA(10).setB(20).setName("Hamza");
    t1.display();

    std::cout << "----------------------------------\n";

    // 3) Passing current object to another function
    t1.passToFunction();

    std::cout << "----------------------------------\n";

    // 4) Getting pointer to current object
    Test *ptr = t1.getPointer();
    std::cout << "Access object via pointer: ";
    ptr->display();

    return 0;
}
