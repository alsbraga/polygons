#ifndef ASORDI_POLYGONS_POLYGON_
#define ASORDI_POLYGONS_POLYGON_

#include <vector>
#include "Point.hpp"

namespace asordi
{
    namespace polygons
    {
        /**
         * @ingroup polygons
         */
        typedef std::vector<Point> Vertices;

        /**
         * @ingroup polygons
         */
        class Polygon
        {
        public:
            Polygon();
            virtual ~Polygon();

            /// Checks if this polygon is complex, i.e., if at least one of its edges intersect.
            bool isComplex() const;

            /// Uses the Winding Number algorithm to determine if a point is inside the polygon.
            bool isInside(const Point &p) const;

        public:
            /// Checks if a polygon is complex, i.e., if at least one of its edges intersect.
            static bool isComplex(const Vertices &vertices);

        public:
            Vertices vertices;
        };
    }
}

#endif // ASORDI_POLYGONS_POLYGON_
