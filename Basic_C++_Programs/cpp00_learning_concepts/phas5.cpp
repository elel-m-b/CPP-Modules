#include <iostream>
#include <string>

// =====================================================================
// ALL concepts: static, const, initializer list, setters, constructor body
// =====================================================================

// Class Example that merges EVERYTHING
class Example
{
private:
    // -----------------------------
    // 1) NORMAL VARIABLES
    int a;
    int b;

    // -----------------------------
    // 2) CONST VARIABLE
    // Must be initialized using initializer list
    const int constValue;

    // -----------------------------
    // 3) REFERENCE VARIABLE
    // Must also be initialized in initializer list
    int &refValue;

    // -----------------------------
    // 4) STRING (class member)
    // We can initialize it in initializer list (faster)
    std::string name;

    // -----------------------------
    // 5) STATIC VARIABLE (shared for all objects)
    // Declaration only here
    static int counter;

public:
    // =================================================================
    // CONSTRUCTOR WITH INITIALIZER LIST
    // Used because:
    // - constValue must be initialized here
    // - refValue must be initialized here
    // - name is faster to init here
    // =================================================================
    Example(int x, int y, int &ref, std::string n) : a(x), b(y), constValue(999), refValue(ref), name(n)
    {
        // -----------------------------
        // Constructor body:
        // runs AFTER initializer list
        // Used for printing, calculations, validation
        // -----------------------------

        std::cout << "Constructor body executed.\n";

        // Increase static counter
        counter++;

        // Example of logic inside constructor body
        if (a < 0)
            a = 0;
        if (b < 0)
            b = 0;
    }

    // =================================================================
    // STATIC MEMBER FUNCTION
    // Can be called without an object
    // =================================================================
    static void showCounter()
    {
        std::cout << "Number of created objects = " << counter << "\n";
    }

    // =================================================================
    // SETTERS (used after object creation)
    // Good for validation
    // =================================================================
    void setA(int x)
    {
        if (x >= 0)
            a = x;
        else
            std::cout << "Invalid value for a!\n";
    }

    void setName(const std::string &newName)
    {
        if (!newName.empty())
            name = newName;
        else
            std::cout << "Name cannot be empty!\n";
    }

    // =================================================================
    // GETTERS (read values)
    // =================================================================
    int getA() const { return a; }
    int getB() const { return b; }
    int getConstValue() const { return constValue; }
    int getRefValue() const { return refValue; }
    std::string getName() const { return name; }

    // =================================================================
    // CONST MEMBER FUNCTION
    // Cannot modify any member variable
    // =================================================================
    void display() const
    {
        std::cout << "Object Data:\n";
        std::cout << "a = " << a << "\n";
        std::cout << "b = " << b << "\n";
        std::cout << "constValue = " << constValue << "\n";
        std::cout << "refValue = " << refValue << "\n";
        std::cout << "name = " << name << "\n";
    }
};

// ======================================================================
// DEFINITION of static variables (MUST be outside class)
// ======================================================================
int Example::counter = 0;

// ======================================================================
// MAIN
// ======================================================================
int main()
{
    int ref = 50;

    // Create object #1
    Example obj1(10, 20, ref, "Ali");
    obj1.display();

    Example::showCounter();  // static function

    // Modify using setters
    obj1.setA(99);
    obj1.setName("Hamza");
    obj1.display();

    std::cout << "----------------------------------\n";

    // Create object #2
    Example obj2(5, -10, ref, "Sara");
    obj2.display();

    Example::showCounter();  // now 2 objects

    return 0;
}
