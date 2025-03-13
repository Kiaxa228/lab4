#ifndef FIGURE_H
#define FIGURE_H

#include "Point.h"
#include <memory>
#include <vector>

template <typename T, typename = std::enable_if_t<std::is_scalar_v<T>>>
class Figure
{
protected:
    std::vector<std::unique_ptr<Point<T>>> points;

public:
    Figure();
    virtual ~Figure() = default;

    Figure(const Figure &other);
    Figure(Figure &&other) noexcept;
    Figure &operator=(const Figure &other);
    Figure &operator=(Figure &&other) noexcept;

    virtual Point<T> geometricCenter() const = 0;
    virtual double area() const = 0;
    virtual void printVertices() const = 0;

    explicit operator double() const;
    bool operator==(const Figure &other) const;
};

#endif