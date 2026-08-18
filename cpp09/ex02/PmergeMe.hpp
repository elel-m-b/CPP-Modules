#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <climits>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <ctime>

class PmergeMe
{
    private:
    std::vector<int> _vector;
    std::deque<int> _deque;

    // Vector helpers
    void fordJohnsonVector(std::vector<int>& v);
    std::vector<size_t> generateJacobsthalOrder(size_t size);
    size_t binarySearchVector(const std::vector<int>& chain,int value,size_t end);

    // Deque helpers
    void fordJohnsonDeque(std::deque<int>& d);
    size_t binarySearchDeque(const std::deque<int>& chain,int value,size_t end);

    public:
    PmergeMe();
    ~PmergeMe();

    int parseNumber(const std::string& str);
    void addNumber(int number);

    const std::vector<int>& getVector() const;
    const std::deque<int>& getDeque() const;

    void sortVector(std::vector<int>& v);
    void sortDeque(std::deque<int>& d);
};

#endif