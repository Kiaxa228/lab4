#include "Hexagon.h"
#include <cmath>
#include <iostream>

#define M_PI 3.14159265358979323846

template <typename T, typename U>
Hexagon<T, U>::Hexagon(T centerX, T centerY, T radius) : centerX_(centerX), centerY_(centerY)
{
    for (int i = 0; i < 6; ++i)
    {
        T angle = 2 * M_PI * i / 6;
        this->points.push_back(std::make_unique<Point<T>>(
            centerX + radius * std::cos(angle),
            centerY + radius * std::sin(angle)));
    }
}

template <typename T, typename U>
Point<T> Hexagon<T, U>::geometricCenter() const
{
    return Point<T>(centerX_, centerY_);
}

template <typename T, typename U>
double Hexagon<T, U>::area() const
{
    double area = 0;
    for (size_t i = 0; i < 6; ++i)
    {
        size_t j = (i + 1) % 6;
        area += (this->points[i]->getX() * this->points[j]->getY() -
                 this->points[j]->getX() * this->points[i]->getY());
    }
    return std::abs(area) / 2;
}

template <typename T, typename U>
void Hexagon<T, U>::printVertices() const
{
    for (const auto &p : this->points)
    {
        std::cout << "(" << p->getX() << ", " << p->getY() << ") ";
    }
    std::cout << std::endl;
}

template class Hexagon<int>;
template class Hexagon<double>;