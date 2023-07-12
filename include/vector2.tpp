#include "vector2.h"

template <typename T>
Vector2<T>::Vector2(T const& x, T const& y)
    : x(x), y(y)
{

}

template <typename T>
Vector2<T> Vector2<T>::operator+(Vector2<T> const& rhs) const
{
    Vector2<T> newVec{};
    newVec.x = x + rhs.x;
    newVec.y = y + rhs.y;

    return newVec;
}

template <typename T>
Vector2<T> Vector2<T>::operator-(Vector2<T> const& rhs) const
{
    return *this + -rhs;
}

template <typename T>
Vector2<T> Vector2<T>::operator*(Vector2<T> const& rhs) const
{

}

template <typename T>
Vector2<T> Vector2<T>::operator-() const
{
    return Vector2{-x, -y};
}

template <typename T>
bool Vector2<T>::operator==(Vector2<T> const& rhs) const
{
    return x == rhs.x && y == rhs.y;
}

template <typename T>
bool Vector2<T>::operator!=(Vector2<T> const& rhs) const
{
    return !(*this == rhs);
}

template <typename T>
std::ostream& operator<<(std::ostream & os, Vector2<T> obj)
{   
    os << "x: " << obj.x << " " << "Y: " << obj.y;

    return os;
}