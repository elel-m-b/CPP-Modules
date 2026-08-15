#ifndef RPN_HPP
#define RPN_HPP
#include <stack>
#include <string>
class RPN
{
    private:
    std::stack<int> _stack;
    bool isOperator(char c) const;
    bool isNumber(char c) const;
    void applyOperation(char operation);

    public:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();

    void calculate(const std::string &expression);
};

#endif