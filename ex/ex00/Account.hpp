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
        ETransferMessage withdraw(Bank &bank, int value);
        ETransferMessage deposit(Bank &bank, int value);
    };

    std::ostream &operator<<(std::ostream &p_os, const Account &p_account);
}
