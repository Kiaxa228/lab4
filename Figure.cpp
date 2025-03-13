#include "Figure.h"

template <typename T, typename U>
Figure<T, U>::Figure() = default;

template <typename T, typename U>
Figure<T, U>::Figure(const Figure &other)
{
    points.reserve(other.points.size());
    for (const auto &p : other.points)
    {
        points.push_back(std::make_unique<Point<T>>(*p));
    }
}

template <typename T, typename U>
Figure<T, U>::Figure(Figure &&other) noexcept = default;

template <typename T, typename U>
Figure<T, U> &Figure<T, U>::operator=(const Figure &other)
{
    if (this != &other)
    {
        points.clear();
        points.reserve(other.points.size());
        for (const auto &p : other.points)
        {
            points.push_back(std::make_unique<Point<T>>(*p));
        }
    }
    return *this;
}

template <typename T, typename U>
Figure<T, U> &Figure<T, U>::operator=(Figure &&other) noexcept = default;

template <typename T, typename U>
Figure<T, U>::operator double() const { return area(); }

template <typename T, typename U>
bool Figure<T, U>::operator==(const Figure &other) const
{
    if (points.size() != other.points.size())
        return false;
    for (size_t i = 0; i < points.size(); ++i)
    {
        if (points[i]->getX() != other.points[i]->getX() ||
            points[i]->getY() != other.points[i]->getY())
        {
            return false;
        }
    }
    return true;
}

template class Figure<int>;
template class Figure<double>;