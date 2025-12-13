
#include "Account.hpp"

namespace Tookuyam
{
    Account::Account() :
        id(-1),
        value(0)
    {

    }

}

std::ostream& Tookuyam::operator<<(std::ostream& p_os, const Account& p_account)
{
    p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
    return (p_os);
}
