#pragma once

#include <limits>
#include <stdexcept>
#include <iostream>

// Moneyはvalueが正の整数であることを期待します。
class Money
{
    typedef size_t money_t;
    money_t value;
    friend std::ostream &operator<<(std::ostream &os, const Money &rhs);
    friend class std::numeric_limits<Money>;

public:
    Money() : value(0) {};
    Money(money_t value) : value(value) {
                           };
    ~Money() {};

    bool operator<(const Money &rhs) { return value < rhs.value; }
    bool operator<=(const Money &rhs) { return value <= rhs.value; }
    Money &operator+=(const Money &rhs) { return *this = value + rhs.value; }
    Money &operator-=(const Money &rhs) { return *this = value - rhs.value; }

    Money &operator=(const Money &rhs)
    {
        if (this != &rhs)
        {
            value = rhs.value;
        }
        return *this;
    }

    Money operator*(const double &rhs)
    {
        if (value == 0)
            return Money(value * rhs);
        if (value > 0 && rhs > std::numeric_limits<money_t>::max() / value)
            throw std::runtime_error("Detect overflow");
        if (value > 0 && rhs < std::numeric_limits<money_t>::min() / value)
            throw std::runtime_error("Detect overflow");
        return Money(value * rhs);
    }

    Money operator+(const Money &rhs)
    {
        if (rhs.value > std::numeric_limits<money_t>::max() - value)
            throw std::runtime_error("Detect overflow");
        return Money(value + rhs.value);
    }

    Money operator-(const Money &rhs)
    {
        if (value < std::numeric_limits<money_t>::min() + rhs.value)
            throw std::runtime_error("Detect overflow");
        return Money(value - rhs.value);
    }
};
std::ostream &operator<<(std::ostream &os, const Money &rhs);

#include "Money.tpp"
