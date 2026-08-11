#include "Span.hpp"

Span::Span(unsigned int N): _maxSize(N)
{
}
Span::Span(const Span& other): _maxSize(other._maxSize),_numbers(other._numbers)
{
}
Span& Span::operator=(const Span& other)
{
    if (this != &other){
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}
Span::~Span()
{
}
void Span::addNumber(int number)
{
    if (_numbers.size() >= _maxSize)
        throw std::out_of_range("Span is full");

    _numbers.push_back(number);
}
unsigned int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");

    std::vector<int> sortedNumbers(_numbers);

    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    unsigned int shortest = static_cast<unsigned int>(
        sortedNumbers[1] - sortedNumbers[0]
    );

    for (std::vector<int>::size_type i = 1;i < sortedNumbers.size();++i){
        unsigned int current = static_cast<unsigned int>(sortedNumbers[i] - sortedNumbers[i - 1]);
        if (current < shortest)
            shortest = current;
    }
    return shortest;
}
unsigned int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");

    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());

    return static_cast<unsigned int>(max - min);
}
unsigned int Span::size() const
{
    return static_cast<unsigned int>(_numbers.size());
}
unsigned int Span::maxSize() const
{
    return _maxSize;
}