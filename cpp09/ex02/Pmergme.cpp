#include "PmergeMe.hpp"


PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other): _vector(other._vector),_deque(other._deque)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vector = other._vector;
        _deque = other._deque;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}


int PmergeMe::parseNumber(const std::string& str)
{
    if (str.empty())
        throw std::invalid_argument("Error");
    for (size_t i = 0; i < str.size(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            throw std::invalid_argument("Error");
    }
    errno = 0;
    char *end = NULL;
    long number = std::strtol(str.c_str(), &end, 10);
    if (errno == ERANGE ||end == NULL ||*end != '\0' || number > INT_MAX)
    {
        throw std::invalid_argument("Error");
    }
    if (number <= 0)
        throw std::invalid_argument("Error");
    return static_cast<int>(number);
}

void PmergeMe::addNumber(int number)
{
    _vector.push_back(number);
    _deque.push_back(number);
}

const std::vector<int>& PmergeMe::getVector() const
{
    return _vector;
}

const std::deque<int>& PmergeMe::getDeque() const
{
    return _deque;
}

void PmergeMe::sortVector(std::vector<int>& v)
{
    fordJohnsonVector(v);
}
void PmergeMe::sortDeque(std::deque<int>& d)
{
    fordJohnsonDeque(d);
}
void PmergeMe::fordJohnsonVector(std::vector<int>& v)
{
    if (v.size() <= 1)
        return;
    std::vector< std::pair<int, int> > pairs;
    size_t i = 0;
    while (i + 1 < v.size())
    {
        int first = v[i];
        int second = v[i + 1];

        if (first > second)
            std::swap(first, second);

        pairs.push_back(std::make_pair(first, second));

        i += 2;
    }
    bool hasStraggler = false;
    int straggler = 0;

    if (i < v.size())
    {
        hasStraggler = true;
        straggler = v[i];
    }
    std::vector<int> bigger;
    for (size_t j = 0; j < pairs.size(); ++j)
        bigger.push_back(pairs[j].second);
    fordJohnsonVector(bigger);

    std::vector< std::pair<int, int> > sortedPairs;
    std::vector<bool> used(pairs.size(), false);

    for (size_t j = 0; j < bigger.size(); ++j)
    {
        for (size_t k = 0; k < pairs.size(); ++k)
        {
            if (!used[k] && pairs[k].second == bigger[j])
            {
                sortedPairs.push_back(pairs[k]);
                used[k] = true;
                break;
            }
        }
    }
    std::vector<int> chain = bigger;
    if (!sortedPairs.empty())
        chain.insert(chain.begin(), sortedPairs[0].first);
    std::vector<size_t> order =
        generateJacobsthalOrderVector(sortedPairs.size());
    for (size_t j = 0; j < order.size(); ++j)
    {
        size_t index = order[j];

        if (index >= sortedPairs.size())
            continue;

        int value = sortedPairs[index].first;
        int partner = sortedPairs[index].second;

        size_t partnerPosition = 0;

        while (partnerPosition < chain.size() &&chain[partnerPosition] < partner)
            ++partnerPosition;
        size_t position =
            binarySearchVector(chain, value, partnerPosition);
        chain.insert(chain.begin() + position, value);
    }
    if (hasStraggler)
    {
        size_t position =
            binarySearchVector(chain, straggler, chain.size());

        chain.insert(chain.begin() + position, straggler);
    }
    v = chain;
}
std::vector<size_t>
PmergeMe::generateJacobsthalOrderVector(size_t size)
{
    std::vector<size_t> order;
    if (size <= 1)
        return order;
    size_t previous = 1;
    size_t jacobsthalPrevious = 1;
    size_t jacobsthalCurrent = 3;

    while (previous < size)
    {
        size_t current = jacobsthalCurrent;

        if (current > size)
            current = size;
        size_t index = current;
        while (index > previous)
        {
            --index;
            if (index > 0)
                order.push_back(index);
        }
        previous = current;
        if (previous >= size)
            break;
        size_t next =jacobsthalCurrent +2 * jacobsthalPrevious;
        jacobsthalPrevious = jacobsthalCurrent;
        jacobsthalCurrent = next;
    }
    for (size_t i = 1; i < size; ++i)
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

size_t PmergeMe::binarySearchVector(const std::vector<int>& chain,int value, size_t end){
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

void PmergeMe::fordJohnsonDeque(std::deque<int>& d)
{
    if (d.size() <= 1)
        return;
    std::deque< std::pair<int, int> > pairs;
    size_t i = 0;
    while (i + 1 < d.size())
    {
        int first = d[i];
        int second = d[i + 1];

        if (first > second)
            std::swap(first, second);
        pairs.push_back(std::make_pair(first, second));
        i += 2;
    }
    bool hasStraggler = false;
    int straggler = 0;

    if (i < d.size())
    {
        hasStraggler = true;
        straggler = d[i];
    }
    std::deque<int> bigger;
    for (size_t j = 0; j < pairs.size(); ++j)
        bigger.push_back(pairs[j].second);
    fordJohnsonDeque(bigger);
    std::deque< std::pair<int, int> > sortedPairs;
    std::deque<bool> used;
    for (size_t j = 0; j < pairs.size(); ++j)
        used.push_back(false);
    for (size_t j = 0; j < bigger.size(); ++j)
    {
        for (size_t k = 0; k < pairs.size(); ++k)
        {
            if (!used[k] && pairs[k].second == bigger[j])
            {
                sortedPairs.push_back(pairs[k]);
                used[k] = true;
                break;
            }
        }
    }
    std::deque<int> chain = bigger;
    if (!sortedPairs.empty())
        chain.push_front(sortedPairs[0].first);
    std::deque<size_t> order =
        generateJacobsthalOrderDeque(sortedPairs.size());
    for (size_t j = 0; j < order.size(); ++j)
    {
        size_t index = order[j];
        if (index >= sortedPairs.size())
            continue;
        int value = sortedPairs[index].first;
        int partner = sortedPairs[index].second;
        size_t partnerPosition = 0;
        while (partnerPosition < chain.size() &&chain[partnerPosition] < partner)
            ++partnerPosition;
        size_t position =binarySearchDeque(chain, value, partnerPosition);
        chain.insert(chain.begin() + position, value);
    }
    if (hasStraggler)
    {
        size_t position = binarySearchDeque(chain, straggler, chain.size());
        chain.insert(chain.begin() + position, straggler);
    }
    d = chain;
}

std::deque<size_t> PmergeMe::generateJacobsthalOrderDeque(size_t size)
{
    std::deque<size_t> order;
    if (size <= 1)
        return order;
    size_t previous = 1;
    size_t jacobsthalPrevious = 1;
    size_t jacobsthalCurrent = 3;
    while (previous < size)
    {
        size_t current = jacobsthalCurrent;
        if (current > size)
            current = size;
        size_t index = current;
        while (index > previous)
        {
            --index;
            if (index > 0)
                order.push_back(index);
        }
        previous = current;
        if (previous >= size)
            break;
        size_t next = jacobsthalCurrent +2 * jacobsthalPrevious;
        jacobsthalPrevious = jacobsthalCurrent;
        jacobsthalCurrent = next;
    }
    for (size_t i = 1; i < size; ++i)
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

size_t PmergeMe::binarySearchDeque(const std::deque<int>& chain,int value,size_t end)
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
