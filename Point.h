#ifndef POINT_H
#define POINT_H

#include <type_traits>

template <typename T, typename = std::enable_if_t<std::is_scalar_v<T>>>
class Point
{
private:
    T x;
    T y;

public:
    Point(T x_ = T(), T y_ = T());
    T getX() const;
    T getY() const;
    void setX(T x_);
    void setY(T y_);
    Point<T> operator/(T scalar) const;
};

#endif