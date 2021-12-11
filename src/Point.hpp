#ifndef ASORDI_POLYGONS_POINT_
#define ASORDI_POLYGONS_POINT_

namespace asordi
{
    namespace polygons
    {
        /**
         * @ingroup polygons
         */
        class Point
        {
        public:
            Point(double x=0.0, double y=0.0);
            virtual ~Point();

            static int compareTo(const Point &l, const Point r);
            bool operator<(const Point &r) const;
            bool operator>(const Point &r) const;
            bool operator==(const Point &r) const;
            bool operator<=(const Point &r) const;
            bool operator>=(const Point &r) const;
            Point operator*(const double d) const;
            Point operator-(const Point &v) const;
            Point operator+(const Point &v) const;
            double perp(const Point &v) const;
            double dot(const Point &v) const;
            double norm() const;
            double dist(const Point &other) const;

        public:
            double x;
            double y;
        };

    }
}

#endif // ASORDI_POLYGONS_POINT_
