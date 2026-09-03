#include "PmergeMe.hpp"

/*
main()
 │
 ├── parse input
 │      ↓
 │   vector<int>
 │
 ├── create pairs
 │      ↓
 │   vector<pair<int,int>>
 │
 ├── compare pairs
 │      ↓
 │   smaller + bigger
 │
 ├── recursively sort bigger
 │      ↓
 │   sorted main chain
 │
 ├── insert smaller
 │      ↓
 │   binary search
 │
 └── final sorted vector
*/

int PmergeMe::parseNumber(const std::string& str)
{
    if (str.empty())
        throw std::invalid_argument("Error");

    for (size_t i = 0; i < str.size(); ++i)
    {
        if (!std::isdigit(str[i]))
            throw std::invalid_argument("Error");
    }

    long number = std::strtol(str.c_str(), NULL, 10);

    if (number > INT_MAX)
        throw std::invalid_argument("Error");

    return static_cast<int>(number);
}

void PmergeMe::addNumber(int number)
{
    _vector.push_back(number);
}

const std::vector<int>& PmergeMe::getVector() const
{
    return _vector;
}

void PmergeMe::sortVector(std::vector<int>& v)
{
    fordJohnsonVector(v);
}

void PmergeMe::fordJohnsonVector(std::vector<int>& v)
{
    if (v.size() <= 1)
        return;

    /*
        STEP 1
        Create pairs.

        Example:

        9 0 2 3 5 8 7 6

        becomes:

        (0,9)
        (2,3)
        (5,8)
        (6,7)
    */

    std::vector< std::pair<int, int> > pairs;

    size_t i = 0;

    for (; i + 1 < v.size(); i += 2)
    {
        int first = v[i];
        int second = v[i + 1];

        if (first > second)
            std::swap(first, second);

        pairs.push_back(std::make_pair(first, second));
    }

    /*
        STEP 2
        Handle odd element.

        Example:

        1 8 3 5 7

        pairs:

        (1,8)
        (3,5)

        straggler:

        7
    */

    bool hasStraggler = (i < v.size());
    int straggler = 0;

    if (hasStraggler)
        straggler = v[i];

    /*
        STEP 3
        Take the bigger element from every pair.

        (0,9) -> 9
        (2,3) -> 3
        (5,8) -> 8
        (6,7) -> 7

        bigger:

        9 3 8 7
    */

    std::vector<int> bigger;

    for (size_t j = 0; j < pairs.size(); ++j)
        bigger.push_back(pairs[j].second);

    /*
        STEP 4
        Recursively sort the bigger elements.

        9 3 8 7
          ↓
        3 7 8 9
    */

    fordJohnsonVector(bigger);

    /*
        STEP 5
        The sorted bigger elements become
        the main chain.

        chain:

        3 7 8 9
    */

    std::vector<int> chain = bigger;

    /*
        STEP 6
        Generate insertion order.

        The order tells us which smaller element
        should be inserted first.
    */

    std::vector<size_t> order = generateJacobsthalOrder(pairs.size());

    /*
        STEP 7
        Insert every smaller element.

        pairs:

        (0,9)
        (2,3)
        (5,8)
        (6,7)

        smaller:

        0 2 5 6
    */

    for (size_t j = 0; j < order.size(); ++j)
    {
        size_t index = order[j];

        int value = pairs[index].first;

        /*
            Find the correct position using
            binary search.
        */

        size_t position = binarySearchVector(chain, value, chain.size());
        chain.insert(chain.begin() + position, value);
    }

    /*
        STEP 8
        If there was an odd element,
        insert it too.
    */

    if (hasStraggler)
    {
        size_t position = binarySearchVector(chain, straggler, chain.size());
        chain.insert(chain.begin() + position, straggler);
    }

    /*
        STEP 9
        Copy sorted chain back into v.
    */

    v = chain;
}

std::vector<size_t>
PmergeMe::generateJacobsthalOrder(size_t size)
{
    std::vector<size_t> order;

    if (size == 0)
        return order;

    /*
        We need every index exactly once.

        Example for 4 elements:

        0 2 1 3

        Example for 5 elements:

        0 2 1 4 3
    */

    order.push_back(0);

    if (size == 1)
        return order;

    /*
        Jacobsthal numbers:

        1, 3, 5, 11, 21, ...

        We use the boundaries to determine
        the insertion groups.
    */

    size_t previous = 1;

    size_t jacobsthalPrevious = 1;
    size_t jacobsthalCurrent = 3;

    while (previous < size)
    {
        size_t current = jacobsthalCurrent;

        if (current > size)
            current = size;

        /*
            Insert backwards from current - 1
            down to previous.
        */

        if (current > previous)
        {
            size_t index = current;

            while (index > previous)
            {
                --index;

                if (index < size)
                    order.push_back(index);
            }
        }

        previous = current;

        if (previous >= size)
            break;

        /*
            Next Jacobsthal number:

            J(n) = J(n-1) + 2 * J(n-2)
        */
        size_t next =jacobsthalCurrent + 2 * jacobsthalPrevious;
        jacobsthalPrevious = jacobsthalCurrent;
        jacobsthalCurrent = next;
    }
    /*
        Safety:
        If anything wasn't added because of the boundaries,
        add the missing indices.

        This guarantees that every pair is inserted exactly once.
    */
    for (size_t i = 0; i < size; ++i)
    {
        bool found = false;

        for (size_t j = 0; j < order.size(); ++j)
        {
            if (order[j] == i)
            {
                found = true;
                break;
            }
        }
        if (!found)
            order.push_back(i);
    }

    return order;
}

size_t PmergeMe::binarySearchVector(const std::vector<int>& chain,int value,size_t end)
{
    size_t left = 0;
    size_t right = end;

    while (left < right)
    {
        size_t middle =
            left + (right - left) / 2;

        if (chain[middle] < value)
            left = middle + 1;
        else
            right = middle;
    }

    return left;
}