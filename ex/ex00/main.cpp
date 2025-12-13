#include <string>

#include "Bank.hpp"
#include "Account.hpp"

void print_message(const Tookuyam::Bank &bank, const std::string &message);

int main()
{
    Tookuyam::Bank bank;
    Tookuyam::Account &_0 = bank.createAccount();
    Tookuyam::Account &_1 = bank.createAccount();

    print_message(bank, "初期状態");

    _0.deposit(bank, 100);
    _1.deposit(bank, 100);
    print_message(bank, "入金後");

    _0.withdraw(bank, 300);
    print_message(bank, "引き出し失敗");

    _0.withdraw(bank, 100);
    print_message(bank, "引き出し成功");

    return (0);
}

void print_message(const Tookuyam::Bank &bank, const std::string &message)
{
    std::cout << message << std::endl;
    std::cout << bank << std::endl;
}
