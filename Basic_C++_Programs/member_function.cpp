/*
    Functions inside a class.
    They can access the object’s data.
*/
#include <iostream>

class counter
{
    private:
    int     count;
    public:
    // void        incremment() {count++;}
    int     getCount(){return count;}
    counter() : count(2) {} // member initializer list.

};

int main()
{
    counter     obj;
    // obj.incremment();
    int     num = obj.getCount();
    counter         c;
    std::cout << num << std::endl;
    return (0);
}