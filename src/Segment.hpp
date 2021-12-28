#ifndef ASORDI_POLYGONS_SEGMENT_
#define ASORDI_POLYGONS_SEGMENT_

#include "Point.hpp"

namespace asordi
{
    namespace polygons
    {
        /**
         * @ingroup polygons
         */
        enum class Intersection
        {
            ERROR = -1,
            DISJOINT = 0,
            PARALLEL = 1,
            COLLINEAR = 2,
            INTERSECT = 3,
            OVERLAP = 4
        };

        /**
         * @ingroup polygons
         */
        class Segment
        {
        public:
            Segment(const Point &p0, const Point &p1);
            virtual ~Segment();
            bool inSegment(const Point &p) const;
            /**
             * @brief Determines if two segments intersect each other of if they are parallel or collinear.
             */
            Intersection intersection(const Segment &s2) const;

            void setEpsilon(const double v);

        public:
            Point p0;
            Point p1;

        private:
            double epsilon_;
            double lo_;
            double hi_;
        };
    }
}

#endif // ASORDI_POLYGONS_SEGMENT_
