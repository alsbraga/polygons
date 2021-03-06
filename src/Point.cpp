#include "Point.hpp"
#include <cmath>

namespace asordi
{
    namespace polygons
    {
        Point::Point(double x, double y) : x(x), y(y) {}
        Point::~Point() {}

        int Point::compareTo(const Point &l, const Point r)
        {
            int result;
            if ((l.x < r.x) || ((l.x == r.x) && (l.y < r.y)))
            {
                result = -1;
            }
            else if ((l.x == r.x) && (l.y == r.y))
            {
                result = 0;
            }
            else
            {
                result = 1;
            }

            return result;
        }

        bool Point::operator<(const Point &r) const
        {
            return compareTo(*this, r) < 0;
        }

        bool Point::operator>(const Point &r) const
        {
            return compareTo(*this, r) > 0;
        }

        bool Point::operator==(const Point &r) const
        {
            return compareTo(*this, r) == 0;
        }

        bool Point::operator!=(const Point &r) const
        {
            return compareTo(*this, r) != 0;
        }

        bool Point::operator<=(const Point &r) const
        {
            return compareTo(*this, r) <= 0;
        }

        bool Point::operator>=(const Point &r) const
        {
            return compareTo(*this, r) >= 0;
        }

        Point Point::operator*(double d) const
        {
            return Point(x * d, y * d);
        }

        Point Point::operator-(const Point &v) const
        {
            return Point(x - v.x, y - v.y);
        }

        Point Point::operator+(const Point &v) const
        {
            return Point(x + v.x, y + v.y);
        }

        double Point::perp(const Point &v) const
        {
            return x * v.y - y * v.x;
        }

        double Point::dot(const Point &v) const
        {
            return x * v.x + y * v.y;
        }
        double Point::norm() const
        {
            return std::sqrt(x * x + y * y);
        }

        double Point::dist(const Point &other) const
        {
            const Point v = *this - other;
            return std::sqrt((v.x * v.x) + (v.y * v.y));
        }
    }
}
