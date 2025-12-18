#pragma once

#include <iostream>

#include "Bank.hpp"
#include "ETransferMessage.hpp"

class Bank::Account
{
    id_t id;
    money_t value;
    money_t debt;
    bool transaction_lock;

    friend ETransferMessage Bank::withdraw(id_t id, money_t value);
    friend ETransferMessage Bank::deposit(id_t id, money_t value);
    friend ETransferMessage Bank::loan(id_t id, money_t value);
    friend ETransferMessage Bank::repay(id_t id, money_t value);
    friend const Account &Bank::createAccount();

    Account();
    Account(id_t id);
    Account(const Account &other);
    Account &operator=(const Account &other);

    bool canPay(money_t value) const;
    bool canRepay(money_t value) const;

public:
    ~Account();
    id_t getId() const;
    money_t getValue() const;
    money_t getDebt() const;
};
std::ostream &operator<<(std::ostream &p_os, const Bank::Account &p_account);
