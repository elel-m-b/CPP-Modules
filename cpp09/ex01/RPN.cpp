#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
RPN::RPN()
{
}

RPN::RPN(const RPN &other): _stack(other._stack)
{
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        _stack = other._stack;
    return *this;
}

RPN::~RPN(){
}

bool RPN::isOperator(char c) const{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool RPN::isNumber(char c) const{
    return c >= '0' && c <= '9';
}

void RPN::applyOperation(char operation)
{
    if (_stack.size() < 2)
        throw std::runtime_error("Error");

    int right = _stack.top();
    _stack.pop();

    int left = _stack.top();
    _stack.pop();

    int result;

    switch (operation)
    {
        case '+':
            result = left + right;
            break;

        case '-':
            result = left - right;
            break;

        case '*':
            result = left * right;
            break;

        case '/':
            if (right == 0)
                throw std::runtime_error("Error");
            result = left / right;
            break;

        default:
            throw std::runtime_error("Error");
    }
    _stack.push(result);
}

void RPN::calculate(const std::string &expression)
{
    if (expression.empty())
        throw std::runtime_error("Error");

    std::istringstream stream(expression);
    std::string token;

    while (stream >> token)
    {
        if (token.size() != 1)
            throw std::runtime_error("Error");
        char c = token[0];
        if (isNumber(c)){
            _stack.push(c - '0');
        }
        else if (isOperator(c))
        {
            applyOperation(c);
        }
        else
        {
            throw std::runtime_error("Error");
        }
    }

    if (_stack.size() != 1)
        throw std::runtime_error("Error");
    std::cout << _stack.top() << std::endl;
}