#include <catch2/catch.hpp>
#include <Segment.hpp>

using namespace asordi;

TEST_CASE("Segment creation", "Segment")
{
    const polygons::Point a(6, 5);
    const polygons::Point b(5, 5);
    polygons::Segment s(a, b);
    CHECK(s.p0 == a);
    CHECK(s.p1 == b);
}
