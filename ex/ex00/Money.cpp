#include "Money.hpp"

std::ostream &operator<<(std::ostream &os, const Money &rhs)
{
    os << rhs.value;
    return os;
}
