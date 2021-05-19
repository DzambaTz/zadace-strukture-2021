#include <iostream>
#include "bank_account.hpp"

void Bank_account::printMenu()
{
    std::cout << "******************************************" << std::endl;
    std::cout << "Actions: " << std::endl;
    std::cout << "\t1. New transaction" << std::endl;
    std::cout << "\t2. Apply transaction" << std::endl;
    std::cout << "\t3. Pending transaction" << std::endl;
    std::cout << "\t4. Discard pending transaction" << std::endl;
    std::cout << "\t5. Balance" << std::endl;
    std::cout << "\t6. Exit" << std::endl;
}

short Bank_account::getOption()
{
    short option;
    do
    {
        std::cout << "Your choice: ";
        std::cin >> option;
        if (option < 1 || option > 6)
        {
            std::cout << "No such option! Try again." << std::endl;
        }
    } while (option < 1 || option > 6);

    return option;
}

void Bank_account::newTransaction()
{
    Transaction temp;
    std::cout << "Enter the transaction amount: ";
    std::cin >> temp.amount;

    std::cout << "Enter the transaction date: ";
    std::cin >> temp.date;

    std::cout << "Enter the transacation time: ";
    std::cin >> temp.time;

    trans_queue.push(temp);

    std::cout << "Transaction successfully added!" << std::endl;
}

void Bank_account::applyTransaction()
{
    try
    {
        balance_ += trans_queue.pop().amount;
        std::cout << "Transaction successfully applied!" << std::endl;
    }
    catch (std::underflow_error e)
    {
        std::cout << "No pending transactions!" << std::endl;
    }
}

void Bank_account::printPendingTransaction()
{
    if (trans_queue.empty())
    {
        std::cout << "No pending transactions!" << std::endl;
        return;
    }

    Transaction t = trans_queue.top();
    std::cout << "Pending transaction: " << std::endl;
    std::cout << "\tAmount: " << t.amount << std::endl;
    std::cout << "\tDate: " << t.date << std::endl;
    std::cout << "\tTime: " << t.time << std::endl;
}
void Bank_account::discardTransaction()
{
    try
    {
        trans_queue.pop();
        std::cout << "Transaction successfully discarded!" << std::endl;
    }
    catch (std::underflow_error e)
    {
        std::cout << "No pending transactions!" << std::endl;
    }
}

double Bank_account::getBalance()
{
    return balance_;
}