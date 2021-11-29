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

        Intersection Segment::intersection(const Segment &s2) const
        {
            Intersection result = Intersection::ERROR;

            return result;
        }
    }
}