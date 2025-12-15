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
