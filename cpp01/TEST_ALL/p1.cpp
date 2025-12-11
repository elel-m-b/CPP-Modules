#include <iostream>
// lifetime
/*
2️⃣ Who controls destruction
  +Stack zombie

- Automatically destroyed.

- No delete needed.

- Destructor runs automatically.

    +Heap zombie

- YOU must call delete.

If you forget → memory leak.
*/

/*
Use heap when:

    You want the zombie to survive after returning from a function.

    Example: newZombie() returns a pointer.
*/

/*
🎯 The REAL POINT of the exercise

    Here is exactly what the authors want you to answer:

    Stack = short lifetime, automatic cleanup
    Heap = long lifetime, manual cleanup (delete)
*/

class Zombie 
{
    private:
    std::string name;

    public:
    // Constructor
    Zombie(std::string name) : name(name) {}

    // Destructor
    ~Zombie() 
    {
        std::cout << this->name << " is destroyed." << std::endl;
    }

    void announce() 
    {
        std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    }
};

// -------------------------
// Create a zombie on the HEAP
// -------------------------
Zombie* newZombie(std::string name) 
{
    return new Zombie(name);   // Stored on the heap
}

// -------------------------
// Create a zombie on the STACK
// -------------------------
void randomChump(std::string name) 
{
    Zombie z(name);     // Stored on the stack
    z.announce();
    // Destructor is called automatically here
}

int main() 
{
    // HEAP example
    Zombie* z = newZombie("Heap");
    z->announce();
    delete z;   // MUST delete (will call destructor)

    // STACK example
    randomChump("stack"); // Automatically destroyed

    return 0;
}
