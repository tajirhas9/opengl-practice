#include <iostream>
#include <cmath>
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

        friend bool operator==(const Point &p1, const Point &p2)
        {
            return (p1.x == p2.x && p1.y == p2.y);
        }
    };

    double points_distance(Point x, Point y) {
        double xx = x.x - y.x;
        xx *= xx;
        double yy = x.y - y.y;
        yy *= yy;

        return sqrt(xx + yy);
    }
}