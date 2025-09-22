#include <iostream>

/*
    2️⃣ File names match class names

    In C++, it’s common to split classes into separate files:

    Header file (.hpp or .h) → contains the class definition (members, methods declarations).

    Source file (.cpp) → contains the method implementations.

    The file name must exactly match the class name (case-sensitive).
*/
// n UpperCamelCase format

// use endl every output message must have a \n

// “You are allowed to use almost everything from the standard library”

// Note that unless explicitly stated otherwise, the using namespace <ns_name> and friend keywords are forbidden. Otherwise, your grade will be -42.

/*
    1️⃣ “You are allowed to use the STL only in Modules 08 and 09”

    STL = Standard Template Library, which includes:

    Containers → std::vector, std::list, std::map, std::set, etc.

    Algorithms → std::sort, std::find, std::count, etc.

    Utilities → std::pair, std::tuple, etc.

    In early modules (before 08), you cannot use STL.

    You have to implement things manually, for example:

    Use arrays or raw pointers instead of std::vector.

    Write your own loops for searching/sorting instead of std::sort.
*/

/*
    #include <vector>      // ❌ not allowed
    #include <list>        // ❌ not allowed
    #include <map>         // ❌ not allowed
    #include <algorithm>   // ❌ not allowed

*/
// You are allowed to create extra .cpp or .hpp files to organize your code better.
// Implementation should go in the source file (.cpp): not .hpp

class BankAccount {      // ✅ class name in UpperCamelCase
private:
    double balance;      // private variable in lowerCamelCase
public:
    void deposit(double amount) { balance += amount; } // function in lowerCamelCase
};

int main()
{

}