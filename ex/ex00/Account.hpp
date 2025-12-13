#pragma once

#include <iostream>

#include "Bank.hpp"

namespace Tookuyam
{
    class Bank;

    class Account
    {
        int id;
        int value;

        friend std::ostream &operator<<(std::ostream &p_os, const Account &p_account);

        Account();

        // public:
        //     const Account &getAccount(Bank int id);
        //     const Account &createAccount(Bank &bank);
    };

    std::ostream &operator<<(std::ostream &p_os, const Account &p_account);
}
