#include "MutantStack.hpp"

#include <iostream>
#include <stack>
#include <list>

static void testBasicOperations()
{
    std::cout << "=== Basic operations ===" << std::endl;

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "top: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "size: " << mstack.size() << std::endl;
    std::cout << "top: " << mstack.top() << std::endl;

    std::cout << std::endl;
}

static void testIterators()
{
    std::cout << "=== Iterator test ===" << std::endl;

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << std::endl;
}

static void testCopy()
{
    std::cout << "=== Copy test ===" << std::endl;

    MutantStack<int> original;

    original.push(10);
    original.push(20);
    original.push(30);

    MutantStack<int> copy(original);

    std::cout << "Original: ";
    MutantStack<int>::iterator it = original.begin();
    while (it != original.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    std::cout << "Copy:     ";
    it = copy.begin();
    while (it != copy.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    std::cout << std::endl;
}

static void testAssignment()
{
    std::cout << "=== Assignment test ===" << std::endl;

    MutantStack<int> first;
    first.push(1);
    first.push(2);
    first.push(3);

    MutantStack<int> second;
    second.push(100);

    second = first;

    MutantStack<int>::iterator it = second.begin();
    while (it != second.end())
    {
        std::cout << *it << " ";
        ++it;
    }

    std::cout << std::endl;
    std::cout << std::endl;
}

static void testConstIterator()
{
    std::cout << "=== Const iterator test ===" << std::endl;

    MutantStack<int> stack;

    stack.push(42);
    stack.push(84);
    stack.push(126);

    const MutantStack<int> constStack(stack);

    MutantStack<int>::const_iterator it = constStack.begin();

    while (it != constStack.end())
    {
        std::cout << *it << " ";
        ++it;
    }

    std::cout << std::endl;
    std::cout << std::endl;
}

static void testAgainstList()
{
    std::cout << "=== MutantStack vs std::list ===" << std::endl;
    MutantStack<int> mstack;
    std::list<int> list;
    int values[] = {5, 17, 3, 5, 737, 0};
    const int size = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < size; ++i)
    {
        mstack.push(values[i]);
        list.push_back(values[i]);
    }

    std::cout << "MutantStack: ";
    MutantStack<int>::iterator mit = mstack.begin();
    while (mit != mstack.end())
    {
        std::cout << *mit << " ";
        ++mit;
    }
    std::cout << std::endl;
    std::cout << "std::list:    ";
    std::list<int>::iterator lit = list.begin();
    while (lit != list.end())
    {
        std::cout << *lit << " ";
        ++lit;
    }
    std::cout << std::endl;
}

static void testStdStackCompatibility()
{
    std::cout << "=== std::stack compatibility ===" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    std::stack<int> normalStack(mstack);
    std::cout << "MutantStack top: " << mstack.top() << std::endl;
    std::cout << "std::stack top:  " << normalStack.top() << std::endl;
    std::cout << std::endl;
}

int main()
{
    testBasicOperations();
    testIterators();
    testCopy();
    testAssignment();
    testConstIterator();
    testAgainstList();
    testStdStackCompatibility();
    return 0;
}