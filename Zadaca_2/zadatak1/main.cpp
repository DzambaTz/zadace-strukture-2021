#include <iostream>
#include "array_stack.hpp"
#include "ll_stack.hpp"

int main()
{
    {
        std::cout << "Array stack:" << std::endl;
        Array_stack<int> stack;

        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.push(5);

        std::cout << "\tStack: " << stack << std::endl;
        std::cout << "\tTop of stack: " << stack.top() << std::endl;
        std::cout << "\tSize of stack: " << stack.size() << std::endl;
        std::cout << std::endl;

        stack.pop();
        stack.pop();

        std::cout << "\tStack: " << stack << std::endl;
        std::cout << "\tTop of stack: " << stack.top() << std::endl;
        std::cout << "\tSize of stack: " << stack.size() << std::endl;
        std::cout << std::endl;

        stack.push(12);
        stack.push(534);
        stack.push(6);
        stack.push(23);
        stack.push(168);

        std::cout << "\tStack: " << stack << std::endl;
        std::cout << "\tTop of stack: " << stack.top() << std::endl;
        std::cout << "\tSize of stack: " << stack.size() << std::endl;
        std::cout << std::endl;

        stack.pop();
        stack.pop();
        stack.pop();
        stack.pop();

        std::cout << "\tStack: " << stack << std::endl;
        std::cout << "\tTop of stack: " << stack.top() << std::endl;
        std::cout << "\tSize of stack: " << stack.size() << std::endl;
        std::cout << std::endl;

        Array_stack<int> stack2;

        stack2 = stack;

        std::cout << "\tStack 1: " << stack << std::endl;
        std::cout << "\tTop of stack1: " << stack.top() << std::endl;
        std::cout << "\tSize of stack: " << stack.size() << std::endl;
        std::cout << std::endl;
        std::cout << "\tStack 2(copy of Stack 1): " << stack2 << std::endl;
        std::cout << "\tTop of stack2: " << stack2.top() << std::endl;
        std::cout << "\tSize of stack2: " << stack2.size() << std::endl;
        std::cout << std::endl;

        if (stack == stack2)
            std::cout << "\tStackovi su isti!" << std::endl;
        if (stack != stack2)
            std::cout << "\tStackovi su razliciti!" << std::endl;
        std::cout << std::endl;

        Array_stack<int> stack3 = stack + stack2;
        std::cout << "\tStack 3: " << stack3 << std::endl;
        std::cout << "\tTop of stack3: " << stack3.top() << std::endl;
        std::cout << "\tSize of stack3: " << stack3.size() << std::endl;
        std::cout << std::endl;
    }
    std::cout << "List stack:" << std::endl;
    List_stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    std::cout << "\tStack: " << stack << std::endl;
    std::cout << "\tTop of stack: " << stack.top() << std::endl;
    std::cout << "\tSize of stack: " << stack.size() << std::endl;
    std::cout << std::endl;

    stack.pop();
    stack.pop();

    std::cout << "\tStack: " << stack << std::endl;
    std::cout << "\tTop of stack: " << stack.top() << std::endl;
    std::cout << "\tSize of stack: " << stack.size() << std::endl;
    std::cout << std::endl;

    stack.push(12);
    stack.push(534);
    stack.push(6);
    stack.push(23);
    stack.push(168);

    std::cout << "\tStack: " << stack << std::endl;
    std::cout << "\tTop of stack: " << stack.top() << std::endl;
    std::cout << "\tSize of stack: " << stack.size() << std::endl;
    std::cout << std::endl;

    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();

    std::cout << "\tStack: " << stack << std::endl;
    std::cout << "\tTop of stack: " << stack.top() << std::endl;
    std::cout << "\tSize of stack: " << stack.size() << std::endl;
    std::cout << std::endl;

    List_stack<int> stack2;

    stack2 = stack;

    std::cout << "\tStack 1: " << stack << std::endl;
    std::cout << "\tTop of stack1: " << stack.top() << std::endl;
    std::cout << "\tSize of stack: " << stack.size() << std::endl;
    std::cout << std::endl;
    std::cout << "\tStack 2(copy of Stack 1): " << stack2 << std::endl;
    std::cout << "\tTop of stack2: " << stack2.top() << std::endl;
    std::cout << "\tSize of stack2: " << stack2.size() << std::endl;
    std::cout << std::endl;

    if (stack == stack2)
        std::cout << "\tStackovi su isti!" << std::endl;
    if (stack != stack2)
        std::cout << "\tStackovi su razliciti!" << std::endl;
    std::cout << std::endl;

    List_stack<int> stack3 = stack + stack2;
    std::cout << "\tStack 3: " << stack3 << std::endl;
    std::cout << "\tTop of stack3: " << stack3.top() << std::endl;
    std::cout << "\tSize of stack3: " << stack3.size() << std::endl;
    std::cout << std::endl;
    return 0;
}