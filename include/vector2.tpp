#include "vector2.h"

template <typename T>
Vector2<T>::Vector2(T const& x, T const& y)
    : x(x), y(y)
{

}

template <typename T>
Vector2<T> Vector2<T>::operator+(Vector2<T> const& rhs)
{
    Vector2<T> newVec{};
    newVec.x = x + rhs.x;
    newVec.y = y + rhs.y;

    return newVec;
}
