#include "PostfixCalc.hpp"
#include <cstddef>
#include <sstream>

bool PostfixCalc::is_operator(const std::string &character)
{
    return character.find_first_not_of("+-*/") == std::string::npos;
}

double PostfixCalc::parse(const std::string &expression)
{
    std::istringstream ss(expression);

    std::string op;
    while (ss >> op)
    {
        if (is_operator(op))
        {
            return do_operation(op);
        }
        else if (is_number(op))
        {
            char *p;
            rpn_stack.push(strtod(op.c_str(), &p));
        }
        continue;
    }
    throw "Expression not valid!";
}

double PostfixCalc::do_operation(const std::string &operation)
{
    double left_operand, right_operand;

    if (rpn_stack.size() < 2)
    {
        throw "Invalid expression!\n";
    }
    right_operand = rpn_stack.top();
    rpn_stack.pop();
    left_operand = rpn_stack.top();
    rpn_stack.pop();

    if (operation == "+")
        return left_operand + right_operand;
    if (operation == "-")
        return left_operand - right_operand;
    if (operation == "*")
        return left_operand * right_operand;
    if (operation == "/")
        return left_operand / right_operand;

    throw "Operation not supported!";
}

bool PostfixCalc::is_number(const std::string &x)
{
    char *p;
    strtod(x.c_str(), &p);
    return *p == 0;
}