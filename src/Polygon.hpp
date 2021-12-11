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
            static bool isComplex(const Vertices &vertices);
        };
    }
}

#endif // ASORDI_POLYGONS_POLYGON_
