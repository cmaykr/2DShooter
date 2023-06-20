#pragma once

template <typename T>
class Vector2
{
public:
    Vector2() = default;

    Vector2<T> operator+(Vector2<T> const& rhs);

    T x;
    T y;
};

#include "vector2.tpp"