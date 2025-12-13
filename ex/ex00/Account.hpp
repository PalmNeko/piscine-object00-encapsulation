#pragma once

#include <iostream>

#include "Bank.hpp"
#include "ETransferMessage.hpp"

namespace Tookuyam
{
    class Bank;

    class Account
    {
        int id;
        int value;
        int debt;
        bool transaction_lock;

        Account();
        Account(int id);
        Account(const Account &other);
        Account &operator=(const Account &other);

    public:
        ~Account();
        static Account *createAccount(Bank &bank);
        bool isEqual(int id) const;
        int getId() const;
        int getValue() const;
        int getDebt() const;
        ETransferMessage withdraw(Bank &bank, int value);
        ETransferMessage deposit(Bank &bank, int value);
        ETransferMessage loan(Bank &bank, int value);
        ETransferMessage repay(Bank &bank, int value);
    };

    std::ostream &operator<<(std::ostream &p_os, const Account &p_account);
}
