#include "MyList.hpp"
#include <iostream>

int main()
{
    std::cout << "Initializer list constructor: " << std::endl;
    MyList<int> moja_lista{12, 54, 23, 54, 123, 85, 236, 712};

    std::cout << "\tLista 1: ";
    for (int x : moja_lista)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::cout << "Push_back i push_front metode: " << std::endl;
    moja_lista.push_back(5);
    moja_lista.push_front(4);
    moja_lista.push_back(7);
    moja_lista.push_front(9);
    std::cout << "\tLista 1: ";
    for (int x : moja_lista)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::cout << "Copy i move constructor: " << std::endl;

    auto moja_lista2 = moja_lista;

    auto moja_lista3 = std::move(moja_lista);

    std::cout << "\tLista 2: ";
    for (int x : moja_lista2)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::cout << "\tLista 3: ";
    for (int x : moja_lista3)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    moja_lista2.pop_front();
    moja_lista2.pop_back();
    moja_lista2.pop_back();
    moja_lista2.pop_front();
    moja_lista2.pop_front();
    std::cout << "Lista 2 nakon pop_back i pop_front: ";
    for (int x : moja_lista2)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::cout << "Iteratori:" << std::endl;
    auto begin = moja_lista2.begin();
    std::cout << "\tLista2 [0] = " << *begin << std::endl;
    std::cout << "\tLista2 [1] = " << *++begin << std::endl;
    std::cout << "\tLista2 [2] = " << *++begin << std::endl;
    auto end = moja_lista2.end();
    std::cout << "\tLista2 [size-1] = " << *--end << std::endl;
    std::cout << "\tLista2 [size-2] = " << *--end << std::endl;
    std::cout << "\tLista2 [size-3] = " << *--end << std::endl;

    std::cout << "Insert i remove:" << std::endl;
    auto pos = moja_lista3.begin();
    pos++;
    pos++;
    moja_lista3.insert(pos, 10000);
    moja_lista3.insert(moja_lista3.begin(), 12345);
    moja_lista3.remove(++moja_lista3.begin());
    moja_lista3.remove(++++++moja_lista3.begin());
    std::cout << "\tLista 3: ";
    for (int x : moja_lista3)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}
