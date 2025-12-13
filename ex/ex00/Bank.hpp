#pragma once

#include <iostream>
#include <vector>

#include "Account.hpp"

namespace Tookuyam
{
    class Account;

    class Bank
    {
        int liquidity;
        std::vector<Account *> clientAccounts;

        friend std::ostream &operator<<(std::ostream &p_os, const Bank &p_bank);

    public:
        Bank();
    };
    std::ostream &operator<<(std::ostream &p_os, const Bank &p_bank);
}
