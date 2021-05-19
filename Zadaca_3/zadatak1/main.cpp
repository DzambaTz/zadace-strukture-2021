#include <iostream>
#include "queue.hpp"

template <typename T>
void printQueue(Queue<T> q, std::string name)
{
    std::cout << name + ": ";
    while (!q.empty())
    {
        std::cout << q.pop() << " ";
    }

    std::cout << std::endl;
}

int main()
{
    Queue<int> queue;

    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);
    queue.push(6);
    queue.push(7);
    queue.push(8);

    printQueue(queue, "Queue 1");

    Queue<int> queue2 = queue;

    printQueue(queue2, "Copy of queue 1 (Queue 2)");

    Queue<int> queue3 = std::move(queue);

    printQueue(queue, "Queue 1 after moving");
    printQueue(queue3, "Moved Queue 1 data (Queue 3)");

    std::cout << "Top of Queue 2 is: " << queue2.top() << std::endl;

    queue2.pop();
    queue2.pop();
    queue2.pop();

    std::cout << "Top of Queue 2 after 3 pops is: " << queue2.top() << std::endl;

    Queue<int> queue4;
    for (int i = 0; i < 150; ++i)
    {
        queue4.push(i / 100);
    }

    printQueue(queue4, "Queue 4");
}