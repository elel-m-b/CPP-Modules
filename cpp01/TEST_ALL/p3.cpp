#include <iostream>


// Mini-Exercises (Stack vs Heap)

// 1️⃣ Lifetime Check
/*
    Q: Create a function createNumber() that declares an int on the stack and returns a pointer to it.
    Will this work? Why or why not?
*/

// int     *createNumber()
// {
//     int     a = 10;
//     int     *b = &a;
//     return (b);
// }

// int main()
// {
//     int   *c = createNumber();
//     std::cout << *c << "\n";
//     return (0);
// }
/*
    Will this work? Why or why not?
    my answer:
    thats work withot the Heap cause we return the value and get int in the main so we don't need the Heap
    in that case
*/

// ----------------------------------------------------------

// 2️⃣ Return an Object

/*
    You must write a function that returns a Dog object created inside the function.

    Q: Should the Dog be allocated on the stack or on the heap?
        Why?
*/
// version 1:
// I don't know why is give me segmentation fault 
// class  Dog
// {
//     private:
//     std::string name;
//     public:
//     Dog();
//     void SetName(std::string n) {n = name;}
//     std::string     getName() {return (name);}
// };

// Dog     *function()
// {
//     Dog         *c1;
//     c1->SetName("Hassan");
//     return (c1);
// }

// int main()
// {
//     Dog *c2 = function();
//     std::cout << c2->getName();
// }

// version 2
// I don't know why is give me nothing 

class  Dog
{
    private:
    std::string name;
    public:
    Dog(){}
    void SetName(std::string n) {name = n;}
    std::string     getName() {return (name);}
};

Dog function()
{
    Dog c1;
    c1.SetName("Hassan");
    return c1;   // return BY VALUE (safe)
}

int main()
{
    Dog c2 = function();
    std::cout << c2.getName();
}
