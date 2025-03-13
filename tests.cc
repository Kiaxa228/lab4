#include <gtest/gtest.h>
#include "Point.h"
#include "Figure.h"
#include "Rhombus.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include "Array.h"
#include <memory>
#include <cmath>

#define M_PI 3.14159265358979323846

TEST(PointTest, ConstructorAndGetters)
{
    Point<int> p(3, 4);
    EXPECT_EQ(p.getX(), 3);
    EXPECT_EQ(p.getY(), 4);
}

TEST(PointTest, Setters)
{
    Point<int> p;
    p.setX(5);
    p.setY(6);
    EXPECT_EQ(p.getX(), 5);
    EXPECT_EQ(p.getY(), 6);
}

TEST(RhombusTest, Area)
{
    Rhombus<int> r(0, 0, 4, 6);
    EXPECT_DOUBLE_EQ(static_cast<double>(r), 12.0);
}

TEST(RhombusTest, GeometricCenter)
{
    Rhombus<int> r(2, 3, 4, 6);
    Point<int> center = r.geometricCenter();
    EXPECT_EQ(center.getX(), 2);
    EXPECT_EQ(center.getY(), 3);
}

TEST(RhombusTest, CopyConstructor)
{
    Rhombus<int> r1(0, 0, 4, 6);
    Rhombus<int> r2(r1);
    EXPECT_TRUE(r1 == r2);
}

TEST(PentagonTest, Area)
{
    Pentagon<double> p(0, 0, 1);
    double expectedArea = 5 * std::sin(2 * M_PI / 5) / 2;
    EXPECT_NEAR(p.area(), expectedArea, 0.0001);
}

TEST(PentagonTest, GeometricCenter)
{
    Pentagon<int> p(5, 5, 3);
    Point<int> center = p.geometricCenter();
    EXPECT_EQ(center.getX(), 5);
    EXPECT_EQ(center.getY(), 5);
}

TEST(HexagonTest, Area)
{
    Hexagon<double> h(0, 0, 1);
    double expectedArea = 3 * std::sqrt(3) / 2;
    EXPECT_NEAR(h.area(), expectedArea, 0.0001);
}

TEST(HexagonTest, GeometricCenter)
{
    Hexagon<int> h(4, 4, 2);
    Point<int> center = h.geometricCenter();
    EXPECT_EQ(center.getX(), 4);
    EXPECT_EQ(center.getY(), 4);
}

TEST(ArrayTest, PushBackAndSize)
{
    Array<Figure<int>> arr;
    arr.push_back(std::make_shared<Rhombus<int>>(0, 0, 4, 6));
    EXPECT_EQ(arr.size(), 1);
}

TEST(ArrayTest, Remove)
{
    Array<Figure<int>> arr;
    arr.push_back(std::make_shared<Rhombus<int>>(0, 0, 4, 6));
    arr.push_back(std::make_shared<Pentagon<int>>(0, 0, 5));
    arr.remove(0);
    EXPECT_EQ(arr.size(), 1);
}

TEST(ArrayTest, AccessOperator)
{
    Array<Figure<int>> arr;
    auto rhombus = std::make_shared<Rhombus<int>>(0, 0, 4, 6);
    arr.push_back(rhombus);
    EXPECT_DOUBLE_EQ(static_cast<double>(*arr[0]), 12.0);
}

TEST(ArrayTest, MoveSemantics)
{
    Array<Rhombus<int>> arr;
    arr.push_back(std::make_shared<Rhombus<int>>(0, 0, 4, 6));
    arr.push_back(std::make_shared<Rhombus<int>>(1, 1, 6, 8));
    arr.push_back(std::make_shared<Rhombus<int>>(2, 2, 8, 10));
    EXPECT_EQ(arr.size(), 3);
    EXPECT_DOUBLE_EQ(static_cast<double>(*arr[0]), 12.0);
}

TEST(PolymorphismTest, FigureArray)
{
    Array<Figure<int>> figures;
    figures.push_back(std::make_shared<Rhombus<int>>(0, 0, 4, 6));
    figures.push_back(std::make_shared<Pentagon<int>>(0, 0, 5));
    figures.push_back(std::make_shared<Hexagon<int>>(0, 0, 3));

    EXPECT_DOUBLE_EQ(figures[0]->area(), 12.0);
    EXPECT_GT(figures[1]->area(), 0);
    EXPECT_GT(figures[2]->area(), 0);
}