#include "Rhombus.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include "Array.h"
#include <iostream>

int main()
{
    Array<Figure<int>> figures;

    int choice;
    while (true)
    {
        std::cout << "1. Add Rhombus\n2. Add Pentagon\n3. Add Hexagon\n4. Print all\n5. Total area\n6. Remove\n7. Exit\n";
        std::cin >> choice;

        if (choice == 7)
            break;

        if (choice >= 1 && choice <= 3)
        {
            int x, y, param1, param2;
            std::cout << "Enter center x, y: ";
            std::cin >> x >> y;

            if (choice == 1)
            {
                std::cout << "Enter diagonals: ";
                std::cin >> param1 >> param2;
                figures.push_back(std::make_shared<Rhombus<int>>(x, y, param1, param2));
            }
            else
            {
                std::cout << "Enter radius: ";
                std::cin >> param1;
                if (choice == 2)
                {
                    figures.push_back(std::make_shared<Pentagon<int>>(x, y, param1));
                }
                else
                {
                    figures.push_back(std::make_shared<Hexagon<int>>(x, y, param1));
                }
            }
        }
        else if (choice == 4)
        {
            for (size_t i = 0; i < figures.size(); ++i)
            {
                std::cout << "Figure " << i << ":\n";
                std::cout << "Vertices: ";
                figures[i]->printVertices();
                auto center = figures[i]->geometricCenter();
                std::cout << "Center: (" << center.getX() << ", " << center.getY() << ")\n";
                std::cout << "Area: " << static_cast<double>(*figures[i]) << "\n\n";
            }
        }
        else if (choice == 5)
        {
            double total = 0;
            for (size_t i = 0; i < figures.size(); ++i)
            {
                total += static_cast<double>(*figures[i]);
            }
            std::cout << "Total area: " << total << "\n";
        }
        else if (choice == 6)
        {
            size_t index;
            std::cout << "Enter index: ";
            std::cin >> index;
            figures.remove(index);
        }
    }

    Array<Rhombus<int>> rhombuses;
    rhombuses.push_back(std::make_shared<Rhombus<int>>(0, 0, 4, 6));

    return 0;
}