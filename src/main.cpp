#include <iostream>
#include "Point.hpp"

using namespace asordi;
int main(int argc, char **argv)
{
    polygons::Point a(6, 5);
    polygons::Point b(5, 5);

    if (a < b)
    {
        std::cout << "a < b";
    }
    else if (a > b)
    {
        std::cout << "a > b";
    }
    else
    {
        std::cout << "a == b";
    }

    std::cout << std::endl;

    return 1;
}
