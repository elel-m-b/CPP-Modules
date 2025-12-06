# ⚔️ 42 C++ Modules ⚔️

<div align="center">
  <img 
    src="https://github.com/user-attachments/assets/74f39eb1-8c7e-4faa-887f-9a33742fe1dc"
    alt="C++"
    style="width: 100%; max-width: 1200px; height: auto; border-radius: 8px;"
  />
</div>

<div align="center">

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![42](https://img.shields.io/badge/42-000000?style=for-the-badge&logo=42&logoColor=white)
![Status](https://img.shields.io/badge/Status-In%20Progress-yellow?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)

**A comprehensive collection of exercises designed to master C++ programming fundamentals**

[Quick Start](#-quick-start) • [Modules](#-modules-overview) • [Resources](#-resources) • [Contributing](#-contributing)

---

</div>

## 📋 Table of Contents

<div align="center">

[About](#-about) • 
[Modules Overview](#-modules-overview) • 
[Quick Start](#-quick-start) • 
[Learning Path](#-learning-path) • 
[Key Concepts](#-key-concepts) • 
[Resources](#-resources) • 
[Study Tips](#-study-tips) • 
[Contributing](#-contributing)

</div>

---

## 🎯 About

<div align="center">

The **42 C++ Modules** represent a carefully curated learning path through C++ programming fundamentals. Following the renowned **42 School curriculum**, this project takes you from basic syntax to advanced programming paradigms.

</div>

### Goal

<div align="center">

> *Not just to learn C++ syntax, but to truly understand the why and how behind Object-Oriented Programming, memory management, and modern C++ practices.*

</div>

### What You'll Learn

<div align="center">

```
Before C++ Modules                    After C++ Modules
━━━━━━━━━━━━━━━━━━━                   ━━━━━━━━━━━━━━━━━━
void* ptr = malloc(...);    →    std::unique_ptr<int> ptr;
strcpy(dest, src);          →    std::string str = "Safe!";
```

**Core Skills**

Object-Oriented Programming • Memory Management • RAII Principles  
Polymorphism & Inheritance • STL Containers • Exception Handling  
Templates • Modern C++ Practices

</div>

---

## 🗺 Modules Overview

<div align="center">

### Learning Progression

```
Module 00: C++ Basics
    ↓
Module 01: Memory & References
    ↓
Module 02: Polymorphism Introduction
    ↓
Module 03: Inheritance
    ↓
Module 04: Abstract Classes & Interfaces
    ↓
Module 05: Exceptions
    ↓
Module 06: Type Casting
    ↓
Module 07: Templates
    ↓
Module 08: STL Containers
    ↓
Module 09: Advanced STL
```

### Difficulty Levels

**Foundation** (Modules 00-02) • **Intermediate** (Modules 03-04) • **Advanced** (Modules 05-09)

</div>

---

## 📦 Module 00 - C++ Basics

<div align="center">

<details>
<summary><strong>Click to expand Module 00</strong></summary>

### Topics Covered

Namespaces • Classes & Objects • Member Functions  
Stdio Streams • Initialization Lists • Static Members • Const Members

### Exercises

| Exercise | Description | Key Concepts |
|:--------:|:------------|:-------------|
| **ex00** | Megaphone | String manipulation, toupper |
| **ex01** | PhoneBook | Classes, arrays, encapsulation |
| **ex02** | Account | Static members, timestamps |

### Example: PhoneBook Class

```cpp
class PhoneBook {
private:
    Contact contacts[8];
    int     currentIndex;
    int     totalContacts;

public:
    PhoneBook();
    void addContact(const Contact& contact);
    void searchContacts() const;
    void displayContact(int index) const;
};
```

### Learning Outcomes
✓ Class structure and encapsulation  
✓ Basic I/O operations  
✓ Member functions and data hiding

**Time Estimate:** 1 week • **Difficulty:** ⭐

</details>

</div>

---

## 🧠 Module 01 - Memory & References

<div align="center">

<details>
<summary><strong>Click to expand Module 01</strong></summary>

### Topics Covered

Memory Allocation (new/delete) • Pointers vs References  
Switch Statements • File Streams • String Manipulation

### Exercises

| Exercise | Description | Key Concepts |
|:--------:|:------------|:-------------|
| **ex00** | BraiiiiinnzZ | Pointers, references |
| **ex01** | Moar brainz! | Dynamic allocation |
| **ex02** | HI THIS IS BRAIN | Memory addresses |
| **ex03** | Unnecessary violence | References in classes |
| **ex04** | Sed is for losers | File I/O, string replace |
| **ex05** | Harl 2.0 | Pointers to member functions |
| **ex06** | Harl filter | Switch statements |

### Example: Weapon Class with References

```cpp
class Weapon {
private:
    std::string type;

public:
    Weapon(const std::string& type);
    const std::string& getType() const;
    void setType(const std::string& type);
};

class HumanB {
private:
    std::string name;
    Weapon*     weapon;  // Pointer for optional weapon

public:
    HumanB(const std::string& name);
    void setWeapon(Weapon& weapon);
    void attack() const;
};
```

### Learning Outcomes
✓ Pointer vs reference differences  
✓ Dynamic memory management  
✓ File I/O operations

**Time Estimate:** 1 week • **Difficulty:** ⭐⭐

</details>

</div>

---

## ⚡ Module 02 - Polymorphism Introduction

<div align="center">

<details>
<summary><strong>Click to expand Module 02</strong></summary>

### Topics Covered

Ad-hoc Polymorphism • Operator Overloading  
Orthodox Canonical Form • Fixed-point Numbers

### Exercises

| Exercise | Description | Key Concepts |
|:--------:|:------------|:-------------|
| **ex00** | First Orthodox Class | Canonical form basics |
| **ex01** | Fixed Point | Operator overloading |
| **ex02** | BSP | Binary Space Partitioning |
| **ex03** | Point and BSP | Advanced operators |

### The Orthodox Canonical Form

```cpp
class Fixed {
private:
    int              _value;
    static const int _fractionalBits = 8;

public:
    // Orthodox Canonical Form (The Big Four)
    Fixed();                              // Default constructor
    Fixed(const Fixed& other);            // Copy constructor
    Fixed& operator=(const Fixed& other); // Copy assignment operator
    ~Fixed();                             // Destructor

    // Conversions
    Fixed(const int value);
    Fixed(const float value);
    float toFloat() const;
    int   toInt() const;

    // Comparison operators
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    // Arithmetic operators
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    // Increment/Decrement
    Fixed& operator++();    // Pre-increment
    Fixed  operator++(int); // Post-increment
    Fixed& operator--();    // Pre-decrement
    Fixed  operator--(int); // Post-decrement

    // Static functions
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
```

### Learning Outcomes
✓ Orthodox Canonical Form mastery  
✓ Operator overloading  
✓ Fixed-point arithmetic

**Time Estimate:** 1-2 weeks • **Difficulty:** ⭐⭐⭐

</details>

</div>

---

## 🔗 Module 03 - Inheritance

<div align="center">

<details>
<summary><strong>Click to expand Module 03</strong></summary>

### Topics Covered

Class Inheritance • Protected Access Specifier  
Virtual Functions • Diamond Problem

### Exercises

| Exercise | Description | Key Concepts |
|:--------:|:------------|:-------------|
| **ex00** | ClapTrap | Base class creation |
| **ex01** | ScavTrap | Single inheritance |
| **ex02** | FragTrap | Multiple derived classes |
| **ex03** | DiamondTrap | Diamond inheritance problem |

### Inheritance Hierarchy

```
           ClapTrap (Base)
              /   \
             /     \
        ScavTrap  FragTrap
             \     /
              \   /
           DiamondTrap
```

### Example Code

```cpp
// Base class
class ClapTrap {
protected:
    std::string _name;
    int         _hitPoints;
    int         _energyPoints;
    int         _attackDamage;

public:
    ClapTrap(const std::string& name);
    virtual ~ClapTrap();
    
    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

// Derived class
class ScavTrap : public ClapTrap {
public:
    ScavTrap(const std::string& name);
    ~ScavTrap();
    
    void attack(const std::string& target); // Override
    void guardGate();
};

// Diamond inheritance solution
class DiamondTrap : public ScavTrap, public FragTrap {
private:
    std::string _name;

public:
    DiamondTrap(const std::string& name);
    ~DiamondTrap();
    
    void whoAmI();
};
```

### Learning Outcomes
✓ Inheritance hierarchies  
✓ Virtual functions and polymorphism  
✓ Diamond problem resolution

**Time Estimate:** 1 week • **Difficulty:** ⭐⭐

</details>

</div>

---

## 🎭 Module 04 - Abstract Classes & Interfaces

<div align="center">

<details>
<summary><strong>Click to expand Module 04</strong></summary>

### Topics Covered

Subtype Polymorphism • Abstract Classes  
Pure Virtual Functions • Interfaces • Deep vs Shallow Copy

### Exercises

| Exercise | Description | Key Concepts |
|:--------:|:------------|:-------------|
| **ex00** | Polymorphism | Virtual functions |
| **ex01** | Brain | Deep copy implementation |
| **ex02** | Abstract class | Pure virtual functions |
| **ex03** | Interface & recap | Interface design patterns |

### Example: Abstract Class

```cpp
// Abstract base class
class Animal {
protected:
    std::string _type;

public:
    Animal();
    virtual ~Animal();
    
    virtual void makeSound() const = 0;  // Pure virtual
    std::string getType() const;
};

// Concrete implementation
class Dog : public Animal {
private:
    Brain* _brain;  // Requires deep copy!

public:
    Dog();
    Dog(const Dog& other);              // Deep copy
    Dog& operator=(const Dog& other);   // Deep copy
    ~Dog();
    
    void makeSound() const;
};

// Interface example
class ICharacter {
public:
    virtual ~ICharacter() {}
    virtual std::string const& getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};
```

### Deep Copy vs Shallow Copy

```cpp
// Shallow copy (default) - BAD!
Dog a;
Dog b = a;  // Both point to same Brain*

// Deep copy (implemented) - GOOD!
Dog::Dog(const Dog& other) {
    _brain = new Brain(*other._brain);  // New allocation
}
```

### Learning Outcomes
✓ Abstract classes and interfaces  
✓ Deep vs shallow copy understanding  
✓ Polymorphic behavior mastery

**Time Estimate:** 1-2 weeks • **Difficulty:** ⭐⭐⭐

</details>

</div>

---

## 🚨 Module 05 - Exceptions

<div align="center">

<details>
<summary><strong>Click to expand Module 05</strong></summary>

### Topics Covered

Try/Catch Blocks • Exception Classes  
Exception Hierarchy • Stack Unwinding • RAII with Exceptions

### Exercises

| Exercise | Description | Key Concepts |
|:--------:|:------------|:-------------|
| **ex00** | Bureaucrat | Basic exception handling |
| **ex01** | Form | Exceptions in classes |
| **ex02** | Abstract forms | Inheritance + exceptions |
| **ex03** | Intern | Factory pattern with exceptions |

### Example: Custom Exceptions

```cpp
class Bureaucrat {
private:
    const std::string _name;
    int              _grade;

public:
    // Nested exception classes
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade is too high!";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade is too low!";
        }
    };

    Bureaucrat(const std::string& name, int grade);
    ~Bureaucrat();

    void incrementGrade();
    void decrementGrade();
    void signForm(Form& form);
    void executeForm(Form const& form);
};

// Usage
try {
    Bureaucrat bob("Bob", 0);  // Throws GradeTooHighException
} catch (const Bureaucrat::GradeTooHighException& e) {
    std::cerr << "Error: " << e.what() << std::endl;
} catch (const std::exception& e) {
    std::cerr << "Unknown error: " << e.what() << std::endl;
}
```

### Learning Outcomes
✓ Exception handling mastery  
✓ Custom exception classes  
✓ Exception safety principles

**Time Estimate:** 1 week • **Difficulty:** ⭐⭐⭐

</details>

</div>

---

## 🎯 Module 06 - Type Casting

<div align="center">

<details>
<summary><strong>Click to expand Module 06</strong></summary>

### Topics Covered

Static Cast • Dynamic Cast  
Const Cast • Reinterpret Cast • Type Identification

### Exercises

| Exercise | Description | Key Concepts |
|:--------:|:------------|:-------------|
| **ex00** | Scalar conversion | static_cast usage |
| **ex01** | Serialization | reinterpret_cast usage |
| **ex02** | Type identification | dynamic_cast for RTTI |

### Cast Types Comparison

| Cast Type | Use Case | Safety Level |
|:---------:|:---------|:------------:|
| `static_cast` | Compile-time conversions | Medium |
| `dynamic_cast` | Runtime polymorphic casting | High |
| `const_cast` | Remove const qualifier | Low |
| `reinterpret_cast` | Low-level reinterpretation | Very Low |

### Example: Type Identification

```cpp
class Base { public: virtual ~Base() {} };
class A : public Base {};
class B : public Base {};
class C : public Base {};

// With pointers
void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

// With references (exception-based)
void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (std::exception&) {}
    
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (std::exception&) {}
    
    std::cout << "C" << std::endl;
}
```

### Learning Outcomes
✓ Different cast types understanding  
✓ Appropriate cast selection  
✓ RTTI (Runtime Type Information)

**Time Estimate:** 1 week • **Difficulty:** ⭐⭐

</details>

</div>

---

## 📐 Module 07 - Templates

<div align="center">

<details>
<summary><strong>Click to expand Module 07</strong></summary>

### Topics Covered

Function Templates • Class Templates  
Template Specialization • Template Instantiation

### Exercises

| Exercise | Description | Key Concepts |
|:--------:|:------------|:-------------|
| **ex00** | Start with templates | Function templates |
| **ex01** | Iter | Template iteration |
| **ex02** | Array | Class template implementation |

### Example: Function Templates

```cpp
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T const& min(T const& a, T const& b) {
    return (a < b) ? a : b;
}

template <typename T>
T const& max(T const& a, T const& b) {
    return (a > b) ? a : b;
}
```

### Example: Class Template

```cpp
template <typename T>
class Array {
private:
    T*           _elements;
    unsigned int _size;

public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();

    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;
    unsigned int size() const;

    class OutOfBoundsException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Index out of bounds!";
        }
    };
};

// Usage
Array<int> numbers(5);
Array<std::string> strings(3);
```

### Learning Outcomes
✓ Function and class templates  
✓ Template instantiation  
✓ Generic programming principles

**Time Estimate:** 1 week • **Difficulty:** ⭐⭐⭐⭐

</details>

</div>

---

## 📚 Module 08 - STL Containers

<div align="center">

<details>
<summary><strong>Click to expand Module 08</strong></summary>

### Topics Covered

STL Containers (vector, list, stack, deque)  
Iterators • Algorithms • Container Adapters

### Exercises

| Exercise | Description | Key Concepts |
|:--------:|:------------|:-------------|
| **ex00** | Easy find | STL algorithm usage |
| **ex01** | Span | Container manipulation |
| **ex02** | Mutated abomination | Stack container extension |

### Example: easyfind

```cpp
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), 
                                        container.end(), 
                                        value);
    if (it == container.end())
        throw std::exception();
    return it;
}
```

### Example: Span Class

```cpp
#include <vector>
#include <algorithm>

class Span {
private:
    unsigned int       _maxSize;
    std::vector<int>   _numbers;

public:
    Span(unsigned int N);
    
    void addNumber(int number);
    void addRange(std::vector<int>::iterator begin, 
                  std::vector<int>::iterator end);
    
    int shortestSpan() const;
    int longestSpan() const;
};
```

### Common STL Algorithms

```cpp
std::find()        // Find element in range
std::sort()        // Sort elements
std::count()       // Count occurrences
std::copy()        // Copy elements
std::for_each()    // Apply function to range
std::transform()   // Transform elements
std::accumulate()  // Accumulate values
```

### Learning Outcomes
✓ STL containers mastery  
✓ Iterator usage  
✓ STL algorithms proficiency

**Time Estimate:** 1-2 weeks • **Difficulty:** ⭐⭐⭐

</details>

</div>

---

## 🎓 Module 09 - Advanced STL

<div align="center">

<details>
<summary><strong>Click to expand Module 09</strong></summary>

### Topics Covered

Advanced STL Algorithms • Function Objects (Functors)  
Predicates • Container Performance • Custom Comparators

### Exercises

| Exercise | Description | Key Concepts |
|:--------:|:------------|:-------------|
| **ex00** | Bitcoin Exchange | std::map usage |
| **ex01** | RPN Calculator | Stack-based algorithm |
| **ex02** | PmergeMe | Merge-insertion sort, performance |

### Example: Bitcoin Exchange

```cpp
#include <map>
#include <string>

class BitcoinExchange {
private:
    std::map<std::string, double> _database;

public:
    BitcoinExchange(const std::string& filename);
    double getRate(const std::string& date) const;
    void processInput(const std::string& filename);
};
```

### Example: RPN Calculator

```cpp
#include <stack>

class RPN {
private:
    std::stack<double> _stack;

public:
    double evaluate(const std::string& expression);
    
private:
    bool isOperator(char c) const;
    void performOperation(char op);
};
```

### Container Performance

| Container | Access | Insertion | Deletion | Best Use Case |
|:---------:|:------:|:---------:|:--------:|:--------------|
| `vector` | O(1) | O(n) | O(n) | Random access, back insertion |
| `deque` | O(1) | O(1)* | O(n) | Both ends operations |
| `list` | O(n) | O(1) | O(1) | Frequent middle insertions |
| `map` | O(log n) | O(log n) | O(log n) | Key-value pairs, sorted |
| `set` | O(log n) | O(log n) | O(log n) | Unique sorted elements |

*O(1) at both ends

### Learning Outcomes
✓ Advanced STL usage  
✓ Container performance understanding  
✓ Algorithm optimization

**Time Estimate:** 1-2 weeks • **Difficulty:** ⭐⭐⭐⭐

</details>

</div>

---

## 🚀 Quick Start

<div align="center">

### Prerequisites

```
C++ Compiler (g++ or clang++)
Make
Git
```

**Recommended Tools**

GDB (Debugging) • Valgrind (Memory Leak Detection)

### Compilation Steps

```bash
# Clone repository
git clone https://github.com/yourusername/42-cpp-modules.git
cd 42-cpp-modules

# Navigate to module
cd Module_00/ex00

# Compile
make

# Run
./program_name

# Clean
make clean    # Remove objects
make fclean   # Remove everything
make re       # Recompile
```

### 42 Norm Compliance

```bash
# Check norm compliance
norminette -R CheckForbiddenSourceHeader *.cpp *.hpp
```

</div>

---

## 📖 Learning Path

<div align="center">

### Recommended Timeline

```
Module 00  →  Module 01  →  Module 02  →  Module 03  →  Module 04
(1 week)     (1 week)     (1-2 weeks)   (1 week)     (1-2 weeks)
                                ↓
Module 05  →  Module 06  →  Module 07  →  Module 08  →  Module 09
(1 week)     (1 week)     (1 week)     (1-2 weeks)   (1-2 weeks)
```

### Total Time: 10-15 weeks (2.5-4 months)

### Difficulty Distribution

| Level | Modules | Difficulty | Time |
|:-----:|:-------:|:----------:|:----:|
| Foundation | 00-02 | ⭐⭐ | 3-5 weeks |
| Intermediate | 03-04 | ⭐⭐⭐ | 2-4 weeks |
| Advanced | 05-09 | ⭐⭐⭐⭐ | 5-7 weeks |

</div>

---

## 🔑 Key Concepts

<div align="center">

### The Four Pillars of OOP

</div>

<details>
<summary><strong>1. Encapsulation</strong> - Data hiding and access control</summary>

<div align="center">

**Definition:** Bundling data and methods within a single unit (class)

```cpp
class BankAccount {
private:
    double balance;  // Hidden

public:
    void deposit(double amount) {
        if (amount > 0)
            balance += amount;
    }
    
    double getBalance() const {
        return balance;
    }
};
```

**Benefits:** Data Hiding • Controlled Access • Easier Maintenance

</div>
</details>

<details>
<summary><strong>2. Inheritance</strong> - Creating new classes from existing ones</summary>

<div align="center">

**Definition:** Mechanism to derive new classes from existing classes

```cpp
class Vehicle {
protected:
    int speed;

public:
    void accelerate() { speed += 10; }
};

class Car : public Vehicle {
private:
    int numberOfDoors;

public:
    void openDoor() { /* ... */ }
};
```

**Types:** Single • Multiple • Hierarchical • Virtual

</div>
</details>

<details>
<summary><strong>3. Polymorphism</strong> - Many forms of the same interface</summary>

<div align="center">

**Definition:** Ability to take multiple forms

```cpp
class Animal {
public:
    virtual void makeSound() = 0;
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void makeSound() { std::cout << "Woof!" << std::endl; }
};

class Cat : public Animal {
public:
    void makeSound() { std::cout << "Meow!" << std::endl; }
};

// Usage
Animal* animal = new Dog();
animal->makeSound();  // Outputs: Woof!
```

**Types:** Compile-time (Overloading) • Runtime (Virtual Functions)

</div>
</details>

<details>
<summary><strong>4. Abstraction</strong> - Hiding implementation details</summary>

<div align="center">

**Definition:** Showing only essential features, hiding complexity

```cpp
class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    
    double area() const {
        return 3.14159 * radius * radius;
    }
    
    double perimeter() const {
        return 2 * 3.14159 * radius;
    }
};
```

**Benefits:** Simplified Interface • Reduced Complexity • Increased Security

</div>
</details>

---

## 📚 Resources

<div align="center">

### Essential Books

| Book | Author | Focus | Level |
|:----:|:------:|:-----:|:-----:|
| C++ Primer | Stanley Lippman | Comprehensive Introduction | Beginner |
| Effective C++ | Scott Meyers | Best Practices | Intermediate |
| More Effective C++ | Scott Meyers | Advanced Techniques | Intermediate |
| Effective Modern C++ | Scott Meyers | C++11/14 Features | Advanced |
| The C++ Programming Language | Bjarne Stroustrup | Complete Reference | All |

### Online Resources

| Resource | Description |
|:--------:|:------------|
| [cppreference.com](https://cppreference.com) | Complete C++ documentation |
| [learncpp.com](https://learncpp.com) | Free C++ tutorials |
| [42 Intranet](https://intra.42.fr) | Official 42 resources |
| [The Cherno](https://youtube.com/c/TheChernoProject) | C++ video series |
| [CppCon](https://youtube.com/user/CppCon) | Conference talks |

### Useful Tools

```bash
# Debugging
gdb ./program              # GNU Debugger
lldb ./program            # LLVM Debugger

# Memory leak detection
valgrind --leak-check=full --show-leak-kinds=all ./program

# Code analysis
cppcheck --enable=all *.cpp

# Static analysis
clang-tidy *.cpp -- -std=c++98
```

</div>

---

## 🎯 Study Tips

<div align="center">

### For Each Module

**Read** → **Understand** → **Plan** → **Code** → **Test** → **Debug** → **Submit**

### Best Practices

```
1. Read the PDF carefully
   └─ Understand requirements
   └─ Note restrictions
   └─ Check allowed functions

2. Plan before coding
   └─ Design class hierarchy
   └─ Consider edge cases
   └─ Think about memory

3. Code incrementally
   └─ Start with basics
   └─ Test each part
   └─ Add features gradually

4. Test thoroughly
   └─ Valid inputs
   └─ Invalid inputs
   └─ Edge cases
   └─ Memory leaks

5. Document your code
   └─ Clear comments
   └─ Explain complex logic
   └─ Document assumptions
```

### Common Pitfalls to Avoid

❌ **Don't Do This**
```cpp
// Forgetting virtual destructor
class Base {
    ~Base() {}  // Should be virtual!
};

// Returning reference to local
std::string& getTemp() {
    std::string temp = "Bad";
    return temp;  // Dangling reference!
}

// Not checking dynamic_cast
Derived* d = dynamic_cast<Derived*>(base);
d->method();  // May crash!
```

✅ **Do This Instead**
```cpp
// Virtual destructor
