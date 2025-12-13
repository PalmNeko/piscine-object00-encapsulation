#pragma once

#include <iostream>
#include <map>

#include "Account.hpp"
#include "ETransferMessage.hpp"

namespace Tookuyam
{
    class Account;

    class Bank
    {
    public:
        static const double inflowRate;

    private:
        int liquidity;
        std::map<int, Account *> clientAccounts;
        int nextId;
        bool transaction_lock;

    public:
        Bank();
        ~Bank();

        const Account &getAccount(int id) const;
        Account &createAccount();
        void deleteAccount(int id);
        int getNextId() const;
        ETransferMessage withdraw(Account &account, int value);
        ETransferMessage deposit(Account &account, int value);
        ETransferMessage loan(Account &account, int value);
        ETransferMessage repay(Account &account, int value);

    private:
        Bank(const Bank &other);
        Bank &operator=(const Bank &other);

        friend std::ostream &operator<<(std::ostream &p_os, const Bank &p_bank);
    };
    std::ostream &operator<<(std::ostream &p_os, const Bank &p_bank);
}
