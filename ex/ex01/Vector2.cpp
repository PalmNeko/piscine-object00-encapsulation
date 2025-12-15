#include <ostream>
#include "Vector2.hpp"

Vector2 &Vector2::operator=(const Vector2 &other)
{
    if (this != &other)
    {
        _x = other._x;
        _y = other._y;
    }
    return *this;
}

bool Vector2::operator<(const Vector2 &rhs) const
{
    if (_y < rhs._y)
        return true;
    if (_y > rhs._y)
        return false;
    return _x < rhs._x;
}

std::ostream &operator<<(std::ostream &os, const Vector2 &rhs)
{
    os << "[" << rhs.x() << "," << rhs.y() << "]";
    return os;
}
