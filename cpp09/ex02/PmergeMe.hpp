#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <stdexcept>

class PmergeMe
{
    private:
    std::vector<int> _vector;
    std::deque<int> _deque;

    public:
    PmergeMe();
    ~PmergeMe();

    int parseNumber(const std::string& str);
    void addNumber(int number);

    const std::vector<int>& getVector() const;
    const std::deque<int>& getDeque() const;

    void createVectorPairs();
    void createDequePairs();
};