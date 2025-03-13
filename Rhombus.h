#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Figure.h"

template <typename T, typename = std::enable_if_t<std::is_scalar_v<T>>>
class Rhombus : public Figure<T>
{
public:
    Rhombus(T centerX, T centerY, T diag1, T diag2);
    Point<T> geometricCenter() const override;
    double area() const override;
    void printVertices() const override;
};

#endif