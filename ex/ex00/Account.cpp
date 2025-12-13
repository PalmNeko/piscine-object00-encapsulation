
#include "Account.hpp"

namespace Tookuyam
{
    Account::Account() : id(-1), value(0), transaction_lock(false)
    {
    }

    Account::Account(int id) : id(id), value(0), transaction_lock(false)
    {
    }

    Account::Account(const Account &other) : id(other.id), value(other.value), transaction_lock(false)
    {
    }

    Account::~Account()
    {
    }

    Account &Account::operator=(const Account &)
    {
        return *this;
    }

    Account *Account::createAccount(Bank &bank)
    {
        return new Account(bank.getNextId());
    }

    bool Account::isEqual(int id) const
    {
        return id == this->id;
    }

    int Account::getId() const
    {
        return id;
    }

    int Account::getValue() const
    {
        return value;
    }

    ETransferMessage Account::withdraw(Bank &bank, int value)
    {
        if (transaction_lock)
            return OK;
        if (this->value < value)
            return NG;
        transaction_lock = true;
        if (bank.withdraw(*this, value) == NG)
        {
            transaction_lock = false;
            return NG;
        }
        this->value -= value;
        transaction_lock = false;
        return OK;
    }

    ETransferMessage Account::deposit(Bank &bank, int value)
    {
        if (transaction_lock)
            return OK;
        transaction_lock = true;
        if (bank.deposit(*this, value) == NG)
        {
            transaction_lock = false;
            return NG;
        }
        this->value += value;
        transaction_lock = false;
        return OK;
    }
}

std::ostream &Tookuyam::operator<<(std::ostream &p_os, const Account &p_account)
{
    p_os << "[" << p_account.getId() << "] - [" << p_account.getValue() << "]";
    return (p_os);
}
