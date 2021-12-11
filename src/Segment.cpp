#include "Segment.hpp"
namespace asordi
{
    namespace polygons
    {
        Segment::Segment(const Point &p0, const Point &p1) : p0(p0), p1(p1){};
        Segment::~Segment(){};

        bool Segment::inSegment(const Point &p) const
        {
            bool result = false;

            if (p0.x != p1.x)
            {
                result = result || ((p0.x <= p.x) && (p.x <= p1.x));
                result = result || ((p0.x >= p.x) && (p.x >= p1.x));
            }
            else
            {
                result = result || ((p0.y <= p.y) && (p.y <= p1.y));
                result = result || ((p0.y >= p.y) && (p.y >= p1.y));
            }

            return result;
        }

        /// It is an implementation of the Dan Sunday's algorithm `intersect2D_2Segments` and is used to check if the
        /// sides of a polygon intersect or overlap each other, thus making it complex. It also detects if the segments
        /// are only points.
        ///
        /// See [Line and Plane Intersection (2D & 3D)](http://geomalgorithms.com/a05-_intersect-1.html)
        ///
        /// The algorithm starts by converting the two segments into vectors ([u] and [v]) and calculating a third vector ([w])
        /// that represents the difference between the start of the two segments.
        ///
        /// Using the perp product between [u] and [v], it is checked if the two segments are parallel.
        ///
        /// If the two segments are parallel, the algorithm checks if they are collinear and if they intersect or
        /// overlap each other. It also checks if either or both are single points and if they intersect, using
        /// vector [w] (will not enter in further details for brevity; please check the reference if you need more info).
        ///
        /// If the vectors are not parallel, check if they intersect.
        ///
        /// It might help to know that the segments are represented by the following equation:
        ///
        /// P(s) = P0 + s * u, where s is a real number and u = (P1 - P0)
        ///
        /// For further details, please check GeomAlgorithms.com.
        /// @see asordi::polygons::Point
        Intersection Segment::intersection(const Segment &s2) const
        {
            Intersection result = Intersection::ERROR;

            return result;
        }
    }
}