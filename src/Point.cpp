#include "Point.hpp"

namespace asordi
{
    namespace polygons
    {
        Point::Point(double x, double y) : x_(x), y_(y) {}
        Point::~Point() {}

        double Point::get_x() const
        {
            return x_;
        }

        double Point::get_y() const
        {
            return y_;
        }

        int Point::compareTo(const Point &l, const Point r)
        {
            int result;
            if ((l.get_x() < r.get_x()) || ((l.get_x() == r.get_x()) && (l.get_y() < r.get_y())))
            {
                result = -1;
            }
            else if ((l.get_x() == r.get_x()) && (l.get_y() == r.get_y()))
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
            return Point(get_x() * d, get_y() * d);
        }

        Point Point::operator-(const Point &v) const
        {
            return Point(get_x() - v.get_x(), get_y() - v.get_y());
        }

        Point Point::operator+(const Point &v) const
        {
            return Point(get_x() + v.get_x(), get_y() + v.get_y());
        }
    }
}
