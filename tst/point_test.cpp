#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <Point.hpp>

using namespace asordi;

TEST_CASE("Point comparison", "Point")
{
    polygons::Point a(6, 5);
    polygons::Point b(5, 5);
    CHECK(a > b);
}
