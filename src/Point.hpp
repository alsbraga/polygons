namespace asordi
{
    namespace polygons
    {

        class Point
        {
        public:
            Point(double x, double y);
            virtual ~Point();

            double get_x() const;
            double get_y() const;
            static int compareTo(const Point &l, const Point r);
            bool operator<(const Point &r) const;
            bool operator>(const Point &r) const;
            bool operator==(const Point &r) const;
            bool operator<=(const Point &r) const;
            bool operator>=(const Point &r) const;
            Point operator*(const double d) const;
            Point operator-(const Point &v) const;
            Point operator+(const Point &v) const;

        private:
            double x_;
            double y_;
        };

    }
}
