#include <catch2/catch.hpp>
#include <Segment.hpp>

using namespace asordi::polygons;

TEST_CASE("Segment creation", "[segment]")
{
    const Point a(6, 5);
    const Point b(5, 5);
    Segment s(a, b);
    CHECK(s.p0 == a);
    CHECK(s.p1 == b);
}

TEST_CASE("Segment parallels", "[segment]")
{
    CHECK(Segment(Point(1, 1), Point(3, 1)).intersection(Segment(Point(1, 2), Point(3, 2))) == Intersection::PARALLEL);
    CHECK(Segment(Point(2, 3), Point(2, 1)).intersection(Segment(Point(3, 3), Point(3, 1))) == Intersection::PARALLEL);
    CHECK(Segment(Point(1, 1), Point(3, 1)).intersection(Segment(Point(1, 1 + 7.25e-4), Point(3, 1 + 7.25e-4))) == Intersection::PARALLEL);
    CHECK(Segment(Point(1, 1), Point(2, 1)).intersection(Segment(Point(2, 1 + 7.25e-4), Point(3, 1 + 7.25e-4))) == Intersection::PARALLEL);
    CHECK(Segment(Point(1, 1), Point(2, 1)).intersection(Segment(Point(2 - 1e-3, 1 + 7.25e-4), Point(3, 1 + 7.25e-4))) == Intersection::PARALLEL);
    CHECK(Segment(Point(1, 1), Point(3, 1)).intersection(Segment(Point(1, 1 + 1e-3), Point(3, 1 + 1e-3))) == Intersection::PARALLEL);
}

TEST_CASE("Segment collinear", "[segment]")
{
    CHECK(Segment(Point(0.5, 2), Point(1.5, 2)).intersection(Segment(Point(2.5, 2), Point(3.5, 2))) == Intersection::COLLINEAR);
    CHECK(Segment(Point(2, 3), Point(2, 2)).intersection(Segment(Point(2, 1.5), Point(2, 0.5))) == Intersection::COLLINEAR);
    CHECK(Segment(Point(1, 1), Point(1, 1)).intersection(Segment(Point(1, 2), Point(1, 2))) == Intersection::COLLINEAR);
    CHECK(Segment(Point(1, 1), Point(1, 1)).intersection(Segment(Point(1 + 1e-2, 1), Point(1 + 1e-2, 1))) == Intersection::COLLINEAR);
}

TEST_CASE("Segment disjoint", "[segment]")
{
    CHECK(Segment(Point(1, 1), Point(2.9, 1)).intersection(Segment(Point(3, 3), Point(3, 1))) == Intersection::DISJOINT);
}

TEST_CASE("Segment intersect", "[segment]")
{
    CHECK(Segment(Point(1, 2), Point(2, 2)).intersection(Segment(Point(2, 2), Point(3, 2))) == Intersection::INTERSECT);
    CHECK(Segment(Point(2, 3), Point(2, 2)).intersection(Segment(Point(2, 2), Point(2, 1))) == Intersection::INTERSECT);
    CHECK(Segment(Point(1, 2), Point(3, 2)).intersection(Segment(Point(2, 3), Point(2, 1))) == Intersection::INTERSECT);
    CHECK(Segment(Point(1, 2), Point(3, 2)).intersection(Segment(Point(1.5, 3), Point(2.5, 1))) == Intersection::INTERSECT);
    CHECK(Segment(Point(1, 1), Point(3, 3)).intersection(Segment(Point(1, 3), Point(3, 1))) == Intersection::INTERSECT);
    CHECK(Segment(Point(1, 1), Point(3, 1)).intersection(Segment(Point(3, 3), Point(3, 1))) == Intersection::INTERSECT);
    CHECK(Segment(Point(1, 1), Point(1, 1)).intersection(Segment(Point(1 + 1e-10, 1), Point(1 + 1e-10, 1))) == Intersection::INTERSECT);
}

TEST_CASE("Segment overlap", "[segment]")
{
    CHECK(Segment(Point(1, 2), Point(2, 2)).intersection(Segment(Point(1.5, 2), Point(2.5, 2))) == Intersection::OVERLAP);
    CHECK(Segment(Point(2, 3), Point(2, 2)).intersection(Segment(Point(2, 2.5), Point(2, 1.5))) == Intersection::OVERLAP);
}
