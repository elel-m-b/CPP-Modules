#include <iostream>

/*
    2️⃣ File names match class names

    In C++, it’s common to split classes into separate files:

    Header file (.hpp or .h) → contains the class definition (members, methods declarations).

    Source file (.cpp) → contains the method implementations.

    The file name must exactly match the class name (case-sensitive).
*/
// n UpperCamelCase format

class BankAccount {      // ✅ class name in UpperCamelCase
private:
    double balance;      // private variable in lowerCamelCase
public:
    void deposit(double amount) { balance += amount; } // function in lowerCamelCase
};

int main()
{

}