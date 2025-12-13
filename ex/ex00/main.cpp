#include <string>

#include "Bank.hpp"
#include "Account.hpp"

void print_message(const Tookuyam::Bank &bank, const std::string &message);

int main()
{
    Tookuyam::Bank bank;
    Tookuyam::Account &_0 = bank.createAccount();
    Tookuyam::Account &_1 = bank.createAccount();

    print_message(bank, "初期状態 (5%)");

    _0.deposit(bank, 100);
    _1.deposit(bank, 100);
    print_message(bank, "入金後 0: 100, 1: 100");

    _0.withdraw(bank, 300);
    print_message(bank, "引き出し失敗");

    _0.withdraw(bank, 95);
    print_message(bank, "引き出し成功 0: 95");

    _0.loan(bank, 115);
    print_message(bank, "融資後 0: 115");

    _0.loan(bank, 10);
    print_message(bank, "融資できず");

    _0.repay(bank, 115);
    print_message(bank, "返済後 0: 115");

    _0.repay(bank, 10);
    print_message(bank, "返済できず");

    bank.deleteAccount(0);
    print_message(bank, "アカウント削除 0");

    bank.deleteAccount(2);
    print_message(bank, "アカウント削除できず");

    bank.createAccount();
    print_message(bank, "空き番ありのアカウント追加");

    return (0);
}

void print_message(const Tookuyam::Bank &bank, const std::string &message)
{
    std::cout << message << std::endl;
    std::cout << bank << std::endl;
}
