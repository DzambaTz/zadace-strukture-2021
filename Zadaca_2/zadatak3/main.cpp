#include <iostream>
#include <string>
#include "PostfixCalc.hpp"

//The calculator supports 4 basic binary operations (+,-,*,/) and 2 operation options.
//The calculator memorizes the last result as well.

//Supported input formats:
// 1. Input 2 operands (numbers) and an operator separated with spaces
//    ex. "5 5 *"  ----> >> 25
// 2. Input a number and an operator. The memorised result is used in the expression (if it exists)
//    ex. "5 /" -----> >> 5 (25/5)

int main()
{
    PostfixCalc calculator;
    while (true)
    {
        std::string expression;
        std::cout << "Enter your expresion(q to exit): ";
        std::getline(std::cin, expression);

        if (expression == "q")
            break;
        try
        {
            double result = calculator.parse(expression);

            std::cout << ">> " << result << std::endl;
        }
        catch (char const *e)
        {
            std::cout << e;
        }
    }
    return 0;
}