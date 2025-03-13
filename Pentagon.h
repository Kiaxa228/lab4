#ifndef PENTAGON_H
#define PENTAGON_H

#include "Figure.h"

template <typename T, typename = std::enable_if_t<std::is_scalar_v<T>>>
class Pentagon : public Figure<T>
{
private:
    T centerX_;
    T centerY_;

public:
    Pentagon(T centerX, T centerY, T radius);
    Point<T> geometricCenter() const override;
    double area() const override;
    void printVertices() const override;
};

#endif