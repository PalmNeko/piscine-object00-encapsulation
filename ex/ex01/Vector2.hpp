#pragma once

class Vector2
{
    float _x;
    float _y;

public:
    Vector2() : _x(0), _y(0) {};
    Vector2(const Vector2 &other) : _x(other._x), _y(other._y) {};
    Vector2(float x, float y) : _x(x), _y(y) {};
    ~Vector2() {};

    Vector2 &operator=(const Vector2 &other);
    bool operator<(const Vector2 &rhs) const { return _y < rhs._y || _x < rhs._x; }

    float x() const { return _x; }
    float y() const { return _y; }
};
