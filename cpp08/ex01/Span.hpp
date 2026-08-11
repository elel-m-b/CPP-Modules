#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iterator>

class Span
{
    private:
    unsigned int        _maxSize;
    std::vector<int>    _numbers;
    public:
    
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();
    
    void addNumber(int number);

    template <typename InputIterator>
    void addNumber(InputIterator begin, InputIterator end)
    {
        unsigned int count = static_cast<unsigned int>(
            std::distance(begin, end)
        );

        if (_numbers.size() + count > _maxSize)
            throw std::out_of_range("Span is full");

        _numbers.insert(_numbers.end(), begin, end);
    }

    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    unsigned int size() const;
    unsigned int maxSize() const;
};

#endif