#pragma once
#include <limits>
#include "Money.hpp"

namespace std
{
    template<>
    class numeric_limits<Money>
    {
    public:
        static const bool is_specialized = true;

        static Money max()
        {
            return Money(numeric_limits<Money::money_t>::max());
        }

        static Money min()
        {
            return Money(0);
        }
    };
}
