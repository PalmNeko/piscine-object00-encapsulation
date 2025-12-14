#pragma once

namespace Tookuyam
{
    class Vector2
    {
        float _x;
        float _y;

    public:
        Vector2();
        Vector2(const Vector2 &other);
        Vector2(float x, float y);
        ~Vector2();

        Vector2 &operator=(const Vector2 &other);

        float x() const;
        float y() const;
    };
}
