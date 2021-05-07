#include <iostream>
#include "ll_stack.hpp"

int main()
{
    size_t n;
    int x;
    std::cout << "How many numbers do you wanna enter?: ";
    std::cin >> n;

    List_stack<int> successors;
    int *input = new int[n];

    for (size_t i = 0; i < n; ++i)
    {
        std::cout << "Enter the " << i + 1 << ". number: ";
        std::cin >> x;
        input[i] = x;
    }

    successors.push(input[0]);
    std::cout << std::endl;

    std::cout << "Largest successor: " << std::endl;

    for (size_t i = 1; i < n; ++i)
    {
        if (successors.empty())
        {
            successors.push(input[i]);
            continue;
        }
        while (!successors.empty() && successors.top() < input[i])
        {
            std::cout << successors.top() << " ---------> " << input[i] << std::endl;
            successors.pop();
        }

        successors.push(input[i]);
    }

    while (!successors.empty())
    {
        std::cout << successors.top() << " ---------> " << -1 << std::endl;
        successors.pop();
    }

    return 0;
}
