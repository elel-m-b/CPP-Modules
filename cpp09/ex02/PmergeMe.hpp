#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <stdexcept>
#include <ctime>
#include <climits>

class PmergeMe
{
private:
    std::vector<int> _vector;

    void fordJohnsonVector(std::vector<int>& v);

    std::vector<size_t> generateJacobsthalOrder(size_t size);

    size_t binarySearchVector(const std::vector<int>& chain,int value,size_t end);

public:

    int parseNumber(const std::string& str);

    void addNumber(int number);

    const std::vector<int>& getVector() const;

    void sortVector(std::vector<int>& v);
};

#endif