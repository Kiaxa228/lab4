#include "Pentagon.h"
#include <cmath>
#include <iostream>
#define M_PI 3.14159265358979323846

template <typename T, typename U>
Pentagon<T, U>::Pentagon(T centerX, T centerY, T radius)
{
    for (int i = 0; i < 5; ++i)
    {
        T angle = 2 * M_PI * i / 5;
        this->points.push_back(std::make_unique<Point<T>>(
            centerX + radius * std::cos(angle),
            centerY + radius * std::sin(angle)));
    }
}

template <typename T, typename U>
Point<T> Pentagon<T, U>::geometricCenter() const
{
    return Point<T>(this->points[0]->getX(), this->points[0]->getY());
}

template <typename T, typename U>
double Pentagon<T, U>::area() const
{
    double area = 0;
    for (size_t i = 0; i < 5; ++i)
    {
        size_t j = (i + 1) % 5;
        area += (this->points[i]->getX() * this->points[j]->getY() -
                 this->points[j]->getX() * this->points[i]->getY());
    }
    return std::abs(area) / 2;
}

template <typename T, typename U>
void Pentagon<T, U>::printVertices() const
{
    for (const auto &p : this->points)
    {
        std::cout << "(" << p->getX() << ", " << p->getY() << ") ";
    }
    std::cout << std::endl;
}

template class Pentagon<int>;
template class Pentagon<double>;