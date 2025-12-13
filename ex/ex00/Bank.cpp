#include "Bank.hpp"

namespace Tookuyam
{
    Bank::Bank() : liquidity(0)
    {
    }
}

std::ostream &Tookuyam::operator<<(std::ostream &p_os, const Bank &p_bank)
{
    p_os << "Bank informations : " << std::endl;
    p_os << "Liquidity : " << p_bank.liquidity << std::endl;

    std::vector<Tookuyam::Account *>::const_iterator it = p_bank.clientAccounts.begin();
    std::vector<Tookuyam::Account *>::const_iterator ite = p_bank.clientAccounts.end();
    while (it != ite)
    {
        p_os << *it << std::endl;
        it++;
    }
    return (p_os);
}
