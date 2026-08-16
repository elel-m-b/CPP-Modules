#include "PmergeMe.hpp"
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

PmergeMe::~PmergeMe(){

}

PmergeMe::PmergeMe(){

}

void PmergeMe::createVectorPairs()
{
    std::vector<std::pair<int, int> > pairs;

    for (size_t i = 0; i + 1 < _vector.size(); i += 2)
    {
        int first = _vector[i];
        int second = _vector[i + 1];

        if (first > second)
            std::swap(first, second);

        pairs.push_back(std::make_pair(first, second));
    }

    for (size_t i = 0; i < pairs.size(); i++){
        std::cout << "(" << pairs[i].first << ","<< pairs[i].second << ") ";
    }

    std::cout << std::endl;
}

void PmergeMe::createDequePairs()
{
    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < _deque.size(); i += 2)
    {
        int first = _deque[i];
        int second = _deque[i + 1];

        if (first > second)
            std::swap(first, second);

        pairs.push_back(std::make_pair(first, second));
    }
    std::cout << "Deque pairs: ";
    for (size_t i = 0; i < pairs.size(); i++)
    {
        std::cout << "("<< pairs[i].first<< ","<< pairs[i].second << ") ";
    }

    std::cout << std::endl;
}