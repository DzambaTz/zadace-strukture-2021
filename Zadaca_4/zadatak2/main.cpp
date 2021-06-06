#include <map>
#include <iostream>
#include <string>

int main()
{
    std::map<std::string, int> mymap;

    mymap["Dzamba"] = 5;

    mymap["Subasa"] = 10;

    mymap["Cicak"] = 20;

    for (const auto &[k, v] : mymap)
    {
        std::cout << k << " " << v << std::endl;
    }
}