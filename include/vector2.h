#pragma once


/// @brief Variable that hold 2 of the same type.  
/// @tparam T Should be a primitive type.
template <typename T>
class Vector2
{
public:
    Vector2() = default;
    Vector2(T const& x, T const& y);

    Vector2<T> operator+(Vector2<T> const& rhs);

    T x;
    T y;
};



#include "vector2.tpp"