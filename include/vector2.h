#pragma once

#include <iostream>

/// @brief Variable that hold 2 of the same type.  
/// @tparam T Should be a primitive type that support adddition, subtraction and multiplication.
template <typename T>
class Vector2
{
public:
    Vector2() = default;
    Vector2(T const& x, T const& y);

    Vector2<T> operator+(Vector2<T> const& rhs) const;
    Vector2<T> operator-(Vector2<T> const& rhs) const;
    Vector2<T> operator+=(Vector2<T> const& rhs);
    T dotProduct(Vector2<T> const& rhs) const;

    Vector2<T> operator-() const;
    
    bool operator==(Vector2<T> const& rhs) const;
    bool operator!=(Vector2<T> const& rhs) const;


    T x;
    T y;
};

template <typename T>
std::ostream& operator<<(std::ostream & os, Vector2<T> obj);

#include "vector2.tpp"
