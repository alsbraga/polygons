#include <Point.hpp>
#include <catch2/catch.hpp>

using namespace asordi;

TEST_CASE("Point arithmetic", "[point]")
{
    const polygons::Point p1(3, 2);
    const polygons::Point p2(2, 3);
    const polygons::Point p3(p1.x + p2.x, p1.y + p2.y);
    const polygons::Point p4(p1.x - p2.x, p1.y - p2.y);
    const polygons::Point p5(p1.x * 2, p1.y * 2);
    CHECK((p1 + p2) == p3);
    CHECK((p1 - p2) == p4);
    CHECK((p1 * 2) == p5);
}

TEST_CASE("Point Perp Product", "[point]")
{
    const polygons::Point p1(3, 2);
    const polygons::Point p2(2, 3);
    const polygons::Point p3 = p1 * -1;
    const polygons::Point p4 = p2 * -1;
    const polygons::Point p5(-3, 2);
    const polygons::Point p6(2, -3);
    CHECK(p1.perp(p1) == 0.0);
    CHECK(p2.perp(p2) == 0.0);
    CHECK(p3.perp(p3) == 0.0);
    CHECK(p4.perp(p4) == 0.0);
    CHECK(p5.perp(p5) == 0.0);
    CHECK(p6.perp(p6) == 0.0);
}

TEST_CASE("Point comparison", "[point]")
{
    const polygons::Point p1(-3, -2);
    const polygons::Point p2(-2, -2);
    const polygons::Point p3(-3, -3);
    const polygons::Point p4(-3, -2);
    SECTION("lower than")
    {
        CHECK(p1 < p2);
        CHECK(p3 < p1);
        CHECK(!(p2 < p1));
        CHECK(!(p1 < p3));
        CHECK(!(p1 < p4));
    }
    SECTION("greater than")
    {
        CHECK(!(p1 > p2));
        CHECK(!(p3 > p1));
        CHECK(p2 > p1);
        CHECK(p1 > p3);
        CHECK(!(p1 > p4));
    }
    SECTION("equal to")
    {
        CHECK(!(p1 == p2));
        CHECK(!(p3 == p1));
        CHECK(!(p2 == p1));
        CHECK(!(p1 == p3));
        CHECK((p1 == p4));
    }
    SECTION("not equal to")
    {
        CHECK((p1 != p2));
        CHECK((p3 != p1));
        CHECK((p2 != p1));
        CHECK((p1 != p3));
        CHECK(!(p1 != p4));
    }
    SECTION("lower than or equal to")
    {
        CHECK((p1 <= p2));
        CHECK((p3 <= p1));
        CHECK(!(p2 <= p1));
        CHECK(!(p1 <= p3));
        CHECK((p1 <= p4));
    }
    SECTION("greater than or equal to")
    {
        CHECK(!(p1 >= p2));
        CHECK(!(p3 >= p1));
        CHECK((p2 >= p1));
        CHECK((p1 >= p3));
        CHECK((p1 >= p4));
    }
}
