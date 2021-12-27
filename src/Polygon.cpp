#include "Polygon.hpp"
#include "Segment.hpp"
#include <utility>
#include <cmath>

namespace asordi
{
    namespace polygons
    {
        Polygon::Polygon() : vertices() {}

        Polygon::~Polygon() {}

        /// See Polygon::isComplex(polygon)
        bool Polygon::isComplex() const
        {
            return Polygon::isComplex(vertices);
        }

        /// Code based on function "polywind": ISBN 978-85-7780-886-1, chap. 21
        /// Other references:
        /// https://en.wikipedia.org/wiki/Winding_number
        /// http://geomalgorithms.com/a03-_inclusion.html
        bool Polygon::isInside(const Point &point) const
        {
            const Vertices &polygon = this->vertices;
            bool result = false;
            if (polygon.size() > 2)
            {
                const double xp = point.x;
                const double yp = point.y;
                int wind = 0;
                double x0 = polygon.end()->x;
                double y0 = polygon.end()->y;
                for (Point const &v : std::as_const(polygon))
                {
                    const double x1 = v.x;
                    const double y1 = v.y;
                    const double cross = ((x0 - xp) * (y1 - yp)) - ((y0 - yp) * (x1 - xp));
                    if (y0 <= yp)
                    {
                        if ((y1 > yp) && (cross > 0.0))
                        {
                            wind++;
                        }
                    }
                    else if ((y1 <= yp) && (cross < 0.0))
                    {
                        wind--;
                    }

                    x0 = x1;
                    y0 = y1;
                }

                result = (std::abs(wind) == 1.0);
            }

            return result;
        }

        /// Sides are represented by segments formed by two consecutive points. Each side
        /// is checked for intersection or overlapping against all other sides. For example,
        /// if the polygon has 5 sides [s1, s2, s3, s4, s5], the checks are:
        ///
        ///     s1 --> s2; s1 --> s3; s1 --> s4; s1 --> s5;
        ///     s2 --> s3; s2 --> s4; s2 --> s5;
        ///     s3 --> s4; s3 --> s5;
        ///     s4 --> s5
        ///
        /// The algorithm has an external and an inner loop. The external one iterates over
        /// all points (i) until the second last. The internal loop iterates over all points (k)
        /// after i until the last one.
        ///
        /// Making:
        ///   - `j = i + 1`
        ///   - `l = k + 1`
        /// at each iteration of the internal loop, two segments are checked: `i --> j` and `k --> l`
        ///
        /// Obs.: Originally I wanted to use Dan Sunday's [simple_Polygon algorithm](http://geomalgorithms.com/a09-_avl_code.html),
        /// which should be less computationally intensive, but I was finding problems to correctly understand and rewrite.
        /// I ended up simply checking for intersections of the polygon segments, also using an algorithm from Dan Sunday.
        /// Check the documentation of class Segment for further details.
        bool Polygon::isComplex(const Vertices &polygon)
        {
            bool isComplex = false;

            const int n = polygon.size();
            for (int i = 0; !isComplex && (i < n); i++)
            {
                const int j = i + 1;
                for (int k = j; !isComplex && (k < n); k++)
                {
                    const int l = (k + 1 < n) ? (k + 1) : 0;
                    const Segment s0(polygon[i], polygon[j]);
                    const Segment s1(polygon[k], polygon[l]);
                    const bool adjacent = (k == j) || (l == i);
                    const Intersection itc = s0.intersection(s1);
                    if (adjacent)
                    {
                        isComplex = (itc == Intersection::OVERLAP);
                    }
                    else
                    {
                        isComplex = (itc == Intersection::INTERSECT) || (itc == Intersection::OVERLAP);
                    }
                }
            }

            return isComplex;
        }
    }
}
