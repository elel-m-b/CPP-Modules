#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <cstdlib>
#include <stdexcept>
#include <climits>
#include <cctype>
#include <cerrno>

class PmergeMe
{
    private:
    std::vector<int> _vector;
    std::deque<int>  _deque;

    void fordJohnsonVector(std::vector<int>& v);
    std::vector<size_t> generateJacobsthalOrderVector(size_t size);
    size_t binarySearchVector(const std::vector<int>& chain,int value,size_t end);
    void fordJohnsonDeque(std::deque<int>& d);
    std::deque<size_t> generateJacobsthalOrderDeque(size_t size);
    size_t binarySearchDeque(const std::deque<int>& chain,int value,size_t end);
    public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    int parseNumber(const std::string& str);
    void addNumber(int number);

    const std::vector<int>& getVector() const;
    const std::deque<int>& getDeque() const;

    void sortVector(std::vector<int>& v);
    void sortDeque(std::deque<int>& d);
};

#endif
