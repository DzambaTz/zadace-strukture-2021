#pragma once
#include <string>
#include "queue.hpp"

struct Transaction
{
    double amount;
    std::string date;
    std::string time;
};

class Bank_account
{
    double balance_ = 0;
    Queue<Transaction> trans_queue;

public:
    void printMenu();
    short getOption();
    void newTransaction();
    void applyTransaction();
    void printPendingTransaction();
    void discardTransaction();
    double getBalance();
};