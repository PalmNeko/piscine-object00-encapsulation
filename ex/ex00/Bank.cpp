#include <stdexcept>
#include "Bank.hpp"

namespace Tookuyam
{
    const double Bank::inflowRate = 0.05;

    Bank::Bank() : liquidity(0), nextId(0), transaction_lock(false)
    {
    }

    Bank::Bank(const Bank &other)
    {
        *this = other;
    }

    Bank::~Bank()
    {
        std::map<int, Tookuyam::Account *>::const_iterator it = clientAccounts.begin();
        std::map<int, Tookuyam::Account *>::const_iterator ite = clientAccounts.end();
        while (it != ite)
        {
            delete it->second;
            it++;
        }
    }

    Bank &Bank::operator=(const Bank &) // cant use
    {
        return *this;
    }

    const Account &Bank::getAccount(int id) const
    {
        std::map<int, Tookuyam::Account *>::const_iterator it = clientAccounts.find(id);
        if (it == clientAccounts.end())
            throw std::runtime_error("Account is not found.");
        return *(it->second);
    }

    Account &Bank::createAccount()
    {
        Account *newAccount = Account::createAccount(*this);
        if (newAccount->getId() != nextId)
        {
            delete newAccount;
            throw std::runtime_error("Unexpected Account Id");
        }
        clientAccounts[nextId] = newAccount;
        nextId += 1;
        return *newAccount;
    }

    void Bank::deleteAccount(int id)
    {
        std::map<int, Tookuyam::Account *>::const_iterator it = clientAccounts.find(id);
        if (it == clientAccounts.end())
            return;
        delete it->second;
        clientAccounts.erase(id);
    }

    int Bank::getNextId() const
    {
        return nextId;
    }

    ETransferMessage Bank::withdraw(Account &account, int value)
    {
        if (transaction_lock)
            return OK;
        if (liquidity < value)
            return NG;
        transaction_lock = true;
        if (account.withdraw(*this, value) == NG)
        {
            transaction_lock = false;
            return NG;
        }
        this->liquidity -= value;
        transaction_lock = false;
        return OK;
    }

    ETransferMessage Bank::deposit(Account &account, int value)
    {
        if (transaction_lock)
            return OK;
        transaction_lock = true;
        if (account.deposit(*this, value) == NG)
        {
            transaction_lock = false;
            return NG;
        }
        this->liquidity += value + (value * Bank::inflowRate);
        transaction_lock = false;
        return OK;
    }

    ETransferMessage Bank::loan(Account &account, int value)
    {
        if (transaction_lock)
            return OK;
        if (this->liquidity < value)
            return NG;
        transaction_lock = true;
        if (account.loan(*this, value) == NG)
        {
            transaction_lock = false;
            return NG;
        }
        this->liquidity -= value;
        transaction_lock = false;
        return OK;
    }

    ETransferMessage Bank::repay(Account &account, int value)
    {
        if (transaction_lock)
            return OK;
        transaction_lock = true;
        if (account.repay(*this, value) == NG)
        {
            transaction_lock = false;
            return NG;
        }
        this->liquidity += value;
        transaction_lock = false;
        return OK;
    }
}

std::ostream &Tookuyam::operator<<(std::ostream &p_os, const Bank &p_bank)
{
    p_os << "Bank informations : " << std::endl;
    p_os << "Liquidity : " << p_bank.liquidity << std::endl;

    std::map<int, Tookuyam::Account *>::const_iterator it = p_bank.clientAccounts.begin();
    std::map<int, Tookuyam::Account *>::const_iterator ite = p_bank.clientAccounts.end();
    while (it != ite)
    {
        p_os << *(it->second) << std::endl;
        it++;
    }
    return (p_os);
}
