#include <iostream>
#include <list>
#include <string>

int main()
{
    std::list<char> storage;

    std::cout << "Welcome to DNA storage. Please enter one of the following options:" << std::endl;
    std::cout << "\t1. Print" << std::endl;
    std::cout << "\t2. Insert <pos> <lanac>" << std::endl;
    std::cout << "\t3. Remove <pos> <len>" << std::endl
              << std::endl;

    int choice;
    while (true)
    {
        std::cout << "Your choice: ";
        std::cin >> choice;

        if (choice < 1 || choice > 3)
        {
            std::cout << "There is no such option. Try again!" << std::endl;
            continue;
        }

        if (choice == 1)
        {
            std::cout << "DNA: ";
            for (const char &x : storage)
            {
                std::cout << x;
            }
            std::cout << std::endl
                      << std::endl;
            continue;
        }

        if (choice == 2)
        {
            int pos;
            std::string value;

            std::cout << "Position: ";
            std::cin >> pos;

            if (pos > storage.size() || pos < 0)
            {
                std::cout << "The entered position is beyond the end of the list!" << std::endl;
                continue;
            }

            std::cout << "Value: ";
            std::cin >> value;

            bool isValid = value.find_first_not_of("ACTG") == std::string::npos;
            if (isValid)
            {
                auto where = storage.begin();
                std::advance(where, pos);

                storage.insert(where, value.begin(), value.end());
            }
            else
            {
                std::cout << "The chain you entered contains invalid characters!" << std::endl;
                continue;
            }
            std::cout << std::endl;
            continue;
        }

        if (choice == 3)
        {
            int pos;
            int len;

            std::cout << "Position: ";
            std::cin >> pos;

            if (pos > storage.size() || pos < 0)
            {
                std::cout << "The entered position is beyond the end of the list!" << std::endl;
                continue;
            }

            std::cout << "Length: ";
            std::cin >> len;

            if (len < 0)
            {
                std::cout << "Length cannot be negative!" << std::endl;
                continue;
            }

            auto first = storage.begin();
            std::advance(first, pos);

            auto last = first;

            if (pos + len > storage.size())
            {
                last = storage.end();
            }
            else
            {
                std::advance(last, len);
            }

            storage.erase(first, last);
            std::cout << std::endl;
        }
    }

    return 0;
}
