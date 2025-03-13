#include "Rhombus.h"
#include <cmath>
#include <iostream>
#define M_PI 3.14159265358979323846

template <typename T, typename U>
Rhombus<T, U>::Rhombus(T centerX, T centerY, T diag1, T diag2)
{
    T halfD1 = diag1 / 2;
    T halfD2 = diag2 / 2;
    this->points.push_back(std::make_unique<Point<T>>(centerX - halfD1, centerY));
    this->points.push_back(std::make_unique<Point<T>>(centerX, centerY + halfD2));
    this->points.push_back(std::make_unique<Point<T>>(centerX + halfD1, centerY));
    this->points.push_back(std::make_unique<Point<T>>(centerX, centerY - halfD2));
}

template <typename T, typename U>
Point<T> Rhombus<T, U>::geometricCenter() const
{
    return Point<T>(this->points[0]->getX() + this->points[2]->getX(),
                    this->points[0]->getY() + this->points[2]->getY()) /
           2;
}

template <typename T, typename U>
double Rhombus<T, U>::area() const
{
    T d1 = std::abs(this->points[2]->getX() - this->points[0]->getX());
    T d2 = std::abs(this->points[1]->getY() - this->points[3]->getY());
    return static_cast<double>(d1 * d2) / 2;
}

template <typename T, typename U>
void Rhombus<T, U>::printVertices() const
{
    for (const auto &p : this->points)
    {
        std::cout << "(" << p->getX() << ", " << p->getY() << ") ";
    }
    std::cout << std::endl;
}

template class Rhombus<int>;
template class Rhombus<double>;