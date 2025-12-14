
#include "Account.hpp"

Bank::Account::Account() : id(-1), value(0), debt(0), transaction_lock(false)
{
}

Bank::Account::Account(id_t id) : id(id), value(0), debt(0), transaction_lock(false)
{
}

Bank::Account::Account(const Account &other) : id(other.id), value(other.value), debt(other.debt), transaction_lock(false)
{
}

Bank::Account::~Account()
{
}

Bank::Account &Bank::Account::operator=(const Account &)
{
    return *this;
}

bool Bank::Account::canPay(Bank::money_t value) const
{
    return value <= this->value;
}

bool Bank::Account::canRepay(Bank::money_t value) const
{
    return value <= this->debt;
}

Bank::id_t Bank::Account::getId() const
{
    return id;
}

Bank::money_t Bank::Account::getValue() const
{
    return value;
}

Bank::money_t Bank::Account::getDebt() const
{
    return debt;
}

std::ostream &operator<<(std::ostream &p_os, const Bank::Account &p_account)
{
    p_os << "[" << p_account.getId() << "] - [" << p_account.getValue() << "] debt: [" << p_account.getDebt() << "]";
    return (p_os);
}
