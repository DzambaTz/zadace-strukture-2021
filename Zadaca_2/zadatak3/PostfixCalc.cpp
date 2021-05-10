#include "PostfixCalc.hpp"
#include <cstddef>
#include <sstream>

//The parse function recieves a string with user input and parses
//it character by character ignoring whitespace.
double PostfixCalc::parse(const std::string &expression)
{
    //We create a istrinstream object because it enables us
    //easier reading from the input expression.
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
            //the char* is needed for the string to double function call and it
            //is an indicator if the conversion was successful, but we already check
            //that in the is_number function so it is kind of redundant.
            char *p;
            rpn_stack.push(strtod(op.c_str(), &p));
        }
    }
    throw "Expression not valid!";
}

double PostfixCalc::do_operation(const std::string &operation)
{
    double left_operand, right_operand;

    //All of our operations are binary so we need at least
    //two elements on the stack to work with
    if (rpn_stack.size() < 2)
    {
        throw "Invalid expression!\n";
    }
    //Read and remove the elements from the stack
    right_operand = rpn_stack.top();
    rpn_stack.pop();
    left_operand = rpn_stack.top();
    rpn_stack.pop();

    //Check which operation are we doing
    if (operation == "+")
    {
        rpn_stack.push(left_operand + right_operand);
        return left_operand + right_operand;
    }

    if (operation == "-")
    {
        rpn_stack.push(left_operand - right_operand);
        return left_operand - right_operand;
    }

    if (operation == "*")
    {
        rpn_stack.push(left_operand * right_operand);
        return left_operand * right_operand;
    }

    if (operation == "/")
    {
        rpn_stack.push(left_operand / right_operand);
        return left_operand / right_operand;
    }

    //In case the operator is not one of the supported ones (should never happen)
    throw "Operation not supported!";
}

//We check if the read character is a double precision floating point number
bool PostfixCalc::is_number(const std::string &x)
{
    char *p;
    strtod(x.c_str(), &p);
    return *p == 0;
}

bool PostfixCalc::is_operator(const std::string &character)
{
    //We check if the read character is one of the supported operators
    return character.find_first_not_of("+-*/") == std::string::npos;
}