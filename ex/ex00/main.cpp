#include <string>
#include <exception>
#include "Bank.hpp"
#include "Account.hpp"

#define EXCEPTION_SAFETY(code)                                        \
    do                                                                \
    {                                                                 \
        try code catch (const std::exception &e)                      \
        {                                                             \
            std::cerr << "\e[31m" << e.what() << "\e[m" << std::endl; \
        }                                                             \
    } while (0)

void print_operate(const std::string &message);
void print_message(const Bank &bank, const std::string &message);
void print_failure(const Bank &bank, const std::string &message);
void print_success(const Bank &bank, const std::string &message);

int main()
{
    Bank bank;
    const Bank::Account &_0 = bank.createAccount();
    const Bank::Account &_1 = bank.createAccount();

    print_message(bank, "初期状態 (入金手数料 5%)");

    print_operate("<処理> ID0 ID1 ID2");
    print_operate("※ - 操作なし  o ターゲット  _ 存在しない");
    std::cout << std::endl;

    print_operate("入金 100円 100円 _");
    bank.deposit(_0.getId(), 100);
    bank.deposit(_1.getId(), 100);
    print_success(bank, "入金成功");

    print_operate("入金 max円 - _");
    EXCEPTION_SAFETY({
        bank.deposit(_0.getId(), std::numeric_limits<Bank::money_t>::max());
    });
    print_failure(bank, "入金失敗 - オーバーフロー");

    print_operate("引き出し 300円 - _");
    EXCEPTION_SAFETY({
        bank.withdraw(_0.getId(), 300);
    });
    print_failure(bank, "引き出し失敗 - 残高不足");

    print_operate("引き出し 95円 - _");
    bank.withdraw(_0.getId(), 95);
    print_success(bank, "引き出し成功");

    print_operate("融資 105円 - _");
    bank.loan(_0.getId(), 105);
    print_message(bank, "融資成功");

    print_operate("融資 10円 - _");
    EXCEPTION_SAFETY({
        bank.loan(_0.getId(), 10);
    });
    print_failure(bank, "融資失敗 - 資金不足");

    print_operate("返済 105円 - _");
    bank.repay(_0.getId(), 105);
    print_success(bank, "返済成功");

    print_operate("返済 10円 - _");
    EXCEPTION_SAFETY({
        bank.repay(_0.getId(), 10);
    });
    print_failure(bank, "返済失敗 - 超過返済");

    print_operate("アカウント削除 o - _");
    bank.deleteAccount(0);
    print_success(bank, "アカウント削除成功");

    print_operate("アカウント削除 _ - o");
    EXCEPTION_SAFETY({
        bank.deleteAccount(2);
    });
    print_failure(bank, "アカウント削除失敗 - 存在しないアカウント");

    print_operate("アカウント作成 _ - o");
    bank.createAccount();
    print_success(bank, "アカウント作成成功");

    print_operate("[]でアカウント取得 o - -");
    EXCEPTION_SAFETY({
        std::cout << bank[0] << std::endl;
    });
    print_failure(bank, "アカウント取得失敗 - 存在しないアカウント");

    print_operate("[]でアカウント取得 _ o -");
    EXCEPTION_SAFETY({
        std::cout << bank[1] << std::endl;
    });
    print_success(bank, "アカウント取得成功");

    return (0);
}

void print_operate(const std::string &message)
{
    std::cout << "\e[34m" << message << "\e[m" << std::endl;
}

void print_message(const Bank &bank, const std::string &message)
{
    std::cout << "\e[34m" << message << "\e[m" << std::endl;
    std::cout << bank << std::endl;
}

void print_failure(const Bank &bank, const std::string &message)
{
    std::cout << "\e[31m" << message << "\e[m" << std::endl;
    std::cout << bank << std::endl;
}

void print_success(const Bank &bank, const std::string &message)
{
    std::cout << "\e[32m" << message << "\e[m" << std::endl;
    std::cout << bank << std::endl;
}
