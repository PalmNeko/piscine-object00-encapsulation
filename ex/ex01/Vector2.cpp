#include "Vector2.hpp"

namespace Tookuyam
{
    Vector2::Vector2() : _x(0), _y(0)
    {
    }

    Vector2::Vector2(const Vector2 &other) : _x(other._x), _y(other._y)
    {
    }

    Vector2::Vector2(float x, float y) : _x(x), _y(y)
    {
    }

    Vector2::~Vector2()
    {
    }

    Vector2 &Vector2::operator=(const Vector2 &other)
    {
        if (this != &other)
        {
            _x = other._x;
            _y = other._y;
        }
        return *this;
    }

    float Vector2::x() const
    {
        return _x;
    }

    float Vector2::y() const
    {
        return _y;
    }

}
