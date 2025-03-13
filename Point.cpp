#include "Point.h"

template <typename T, typename U>
Point<T, U>::Point(T x_, T y_) : x(x_), y(y_) {}

template <typename T, typename U>
T Point<T, U>::getX() const { return x; }

template <typename T, typename U>
T Point<T, U>::getY() const { return y; }

template <typename T, typename U>
void Point<T, U>::setX(T x_) { x = x_; }

template <typename T, typename U>
void Point<T, U>::setY(T y_) { y = y_; }

template <typename T, typename U>
Point<T> Point<T, U>::operator/(T scalar) const
{
    return Point<T>(x / scalar, y / scalar);
}

template class Point<int>;
template class Point<double>;