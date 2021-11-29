#ifndef ASORDI_POLYGONS_SEGMENT_
#define ASORDI_POLYGONS_SEGMENT_

#include "Point.hpp"

namespace asordi
{
    namespace polygons
    {
        enum class Intersection
        {
            ERROR = -1,
            DISJOINT = 0,
            PARALLEL = 1,
            COLLINEAR = 2,
            INTERSECT = 3,
            OVERLAP = 4
        };

        class Segment
        {
        public:
            Segment(const Point &p0, const Point &p1);
            virtual ~Segment();
            bool inSegment(const Point &p) const;
            Intersection intersection(const Segment &s2) const;

        public:
            Point p0;
            Point p1;
        };
    }
}

#endif // ASORDI_POLYGONS_SEGMENT_
