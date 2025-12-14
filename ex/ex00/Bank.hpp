#pragma once

#include <iostream>
#include <map>

#include "Money.hpp"
#include "ETransferMessage.hpp"

class Bank
{
public:
    class Account;
    typedef int id_t;
    typedef Money money_t;
    typedef std::map<id_t, Account *> accounts_t;

public:
    static const double inflowRate;

private:
    money_t liquidity;
    accounts_t clientAccounts;
    id_t nextId;
    Account &getAccount(id_t id) const;
    bool canPay(money_t value) const;

public:
    Bank();
    ~Bank();

    const Account &operator[](id_t id) const;
    const Account &createAccount();
    void deleteAccount(id_t id);
    ETransferMessage withdraw(id_t id, money_t value);
    ETransferMessage deposit(id_t id, money_t value);
    ETransferMessage loan(id_t id, money_t value);
    ETransferMessage repay(id_t id, money_t value);

private:
    Bank(const Bank &other);
    Bank &operator=(const Bank &other);

    friend std::ostream &operator<<(std::ostream &p_os, const Bank &p_bank);
};
std::ostream &operator<<(std::ostream &p_os, const Bank &p_bank);
