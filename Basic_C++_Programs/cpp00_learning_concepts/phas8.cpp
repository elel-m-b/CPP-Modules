#include <iostream>
/*
    C++ References: Complete Explanation from Basics to Internals
*/

// Basic Definition

/*
    A reference is an alias - an alternative name for an existing variable. 
    It's not a separate object, but another way to access the same memory location.
*/

/*
    int main() 
    {
        int original = 42;
        
        // Create a reference to 'original'
        int& ref = original;
        
        std::cout << "original: " << original << std::endl;  // 42
        std::cout << "ref: " << ref << std::endl;            // 42
        
        // Modifying through reference affects the original
        ref = 100;
        std::cout << "after ref=100:" << std::endl;
        std::cout << "original: " << original << std::endl;  // 100
        std::cout << "ref: " << ref << std::endl;            // 100
        
        return 0;
    }
*/

//  -> How References Work Behind the Scenes


void reference_internals() 
{
    int original = 100;
    int& ref = original;
    
    // What the compiler sees:
    /*
    Memory layout:
    +-----------------+-----------------+
    | Variable Name   | Memory Address  |
    +-----------------+-----------------+
    | original        | 0x7ffd1234      |
    | ref             | 0x7ffd1234      | ← SAME address!
    +-----------------+-----------------+
    
    Both names refer to the same memory location.
    The reference is essentially a compile-time alias.
    */
    
    std::cout << "Address of original: " << &original << std::endl;
    std::cout << "Address of ref: " << &ref << std::endl;
    // Both addresses will be identical!
}

// Detailed Memory Layout Examples

// Example 1: Basic Reference

void basic_reference_layout() 
{
    int a = 42;
    int& ref_a = a;
    
    /*
    Stack Memory Layout:
    +---------------+---------+-----------+
    | Variable      | Address | Value     |
    +---------------+---------+-----------+
    | a             | 0x1000  | 42        |
    | ref_a         | 0x1000  | (alias)   | ← Same address as a!
    +---------------+---------+-----------+
    
    There's NO separate memory allocated for ref_a.
    It's just another name for the same memory location.
    */
}

// Example 2: References in Functions

void modify(int& param) 
{
    param = 999;  // Directly modifies the original variable
}

void function_references() 
{
    int value = 100;
    
    /*
    Before function call:
    Stack:
    +-----------+---------+-------+
    | value     | 0x2000  | 100   |
    +-----------+---------+-------+
    */
    
    modify(value);
    
    /*
    Inside modify():
    +-----------+---------+-------+
    | param     | 0x2000  | 100   | ← param is reference to value
    +-----------+---------+-------+
    
    After param = 999:
    +-----------+---------+-------+
    | value     | 0x2000  | 999   | ← Original changed!
    +-----------+---------+-------+
    */
    
    std::cout << "value after modify: " << value << std::endl;  // 999
}

// Example 3: Reference vs Pointer Memory

void compare_memory_layout() 
{
    int data = 50;
    int& ref = data;
    int* ptr = &data;
    
    /*
    Memory Layout:
    +-----------+---------+----------+-------------------+
    | Variable  | Address | Value    | Explanation       |
    +-----------+---------+----------+-------------------+
    | data      | 0x3000  | 50       | Actual data       |
    | ref       | 0x3000  | (alias)  | Alias for data    |
    | ptr       | 0x3008  | 0x3000   | Pointer to data   |
    +-----------+---------+----------+-------------------+
    
    Key differences:
    - ref: No memory overhead, compile-time only
    - ptr: Uses memory (8 bytes on 64-bit) to store address
    */
    
    std::cout << "sizeof(ref): " << sizeof(ref) << std::endl;  // sizeof(int)
    std::cout << "sizeof(ptr): " << sizeof(ptr) << std::endl;  // 8 (64-bit)
}

// How Compilers Handle References


// From compiler's perspective:

// Source code:
void compiler_view() 
{
    int x = 10;
    int& r = x;
    r = r + 5;
}

/*
    What the compiler actually generates:
- The reference 'r' is replaced everywhere with 'x'
- No runtime cost for reference usage
- Equivalent code without references:

void equivalent_without_references() 
{
    int x = 10;
    // int& r = x; is completely eliminated
    x = x + 5;  // r = r + 5 becomes x = x + 5
}
*/

// Reference Lifetime Extension

void lifetime_extension() 
{
    // Temporary objects can have extended lifetime when bound to const reference
    const int& temp_ref = 42;  // Temporary int(42) lifetime extended
    
    /*
    What happens:
    1. Temporary int(42) is created
    2. const reference binds to it  
    3. Temporary's lifetime is extended to match reference's scope
    4. No dangling reference
    */
    
    std::cout << temp_ref << std::endl;  // Safe - object still exists
}
