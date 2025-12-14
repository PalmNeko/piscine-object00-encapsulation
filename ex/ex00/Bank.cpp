#include <stdexcept>
#include "Bank.hpp"
#include "Account.hpp"

const double Bank::inflowRate = 0.05;

Bank::Bank() : liquidity(0), nextId(0)
{
}

Bank::Bank(const Bank &)
{
    throw std::runtime_error("don't supported");
}

Bank::~Bank()
{
    accounts_t::const_iterator it = clientAccounts.begin();
    accounts_t::const_iterator ite = clientAccounts.end();
    while (it != ite)
    {
        delete it->second;
        it++;
    }
}

Bank &Bank::operator=(const Bank &) // cant use
{
    throw std::runtime_error("don't supported");
}

Bank::Account &Bank::getAccount(id_t id) const
{
    accounts_t::const_iterator it = clientAccounts.find(id);
    if (it == clientAccounts.end())
        throw std::runtime_error("Account is not found.");
    return *(it->second);
}

const Bank::Account &Bank::createAccount()
{
    Account *newAccount = new Account(nextId);
    clientAccounts[nextId] = newAccount;
    nextId += 1;
    return *newAccount;
}

void Bank::deleteAccount(id_t id)
{
    Account &account = getAccount(id);
    clientAccounts.erase(account.getId());
}

ETransferMessage Bank::withdraw(id_t id, money_t value)
{
    Account &account = getAccount(id);
    if (canPay(value) == false)
        throw std::runtime_error("Bank has no enough liquidity.");
    if (account.canPay(value) == false)
        throw std::runtime_error("Account has no enough value.");
    liquidity -= value;
    account.value -= value;
    return OK;
}

ETransferMessage Bank::deposit(id_t id, money_t value)
{
    Account &account = getAccount(id);
    money_t new_liquidity = liquidity + value;
    money_t new_value = account.value + value - (value * Bank::inflowRate);
    liquidity = new_liquidity;
    account.value = new_value;
    return OK;
}

ETransferMessage Bank::loan(id_t id, money_t value)
{
    Account &account = getAccount(id);
    if (canPay(value) == false)
        throw std::runtime_error("Bank has no enough liquidity.");
    account.debt += value;
    liquidity -= value;
    return OK;
}

ETransferMessage Bank::repay(id_t id, money_t value)
{
    Account &account = getAccount(id);
    if (account.canRepay(value) == false)
        throw std::runtime_error("Bank has no enough liquidity.");
    account.debt -= value;
    liquidity += value;
    return OK;
}

bool Bank::canPay(money_t value) const
{
    return value <= liquidity;
}

const Bank::Account &Bank::operator[](id_t id) const
{
    return getAccount(id);
}


std::ostream &operator<<(std::ostream &p_os, const Bank &p_bank)
{
    p_os << "Bank informations : " << std::endl;
    p_os << "Liquidity : " << p_bank.liquidity << std::endl;

    Bank::accounts_t::const_iterator it = p_bank.clientAccounts.begin();
    Bank::accounts_t::const_iterator ite = p_bank.clientAccounts.end();
    while (it != ite)
    {
        p_os << *(it->second) << std::endl;
        it++;
    }
    return (p_os);
}
