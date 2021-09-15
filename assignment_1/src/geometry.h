#include <iostream>

namespace geo
{

    const double eps = 0.000000001;

    class Point
    {
    public:
        Point() : x(0), y(0) {}
        Point(double x, double y) : x(x), y(y) {}
        double x, y;
        friend std::istream &operator>>(std::istream &input, Point &p)
        {
            input >> p.x >> p.y;
            return input;
        }

        friend std::ostream &operator<<(std::ostream &output, Point &p)
        {
            output << "(" << p.x << ", " << p.y << ")";
            return output;
        }
    };
}