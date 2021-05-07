#include <iostream>
#include <string>
#include "PostfixCalc.hpp"

int main()
{
    while (true)
    {
        std::string expression;
        std::cout << "Enter your expresion(q to exit): ";
        std::getline(std::cin, expression);

        if (expression == "q")
            break;

        PostfixCalc calculator;
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