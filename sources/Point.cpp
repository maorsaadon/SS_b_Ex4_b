#include <stdio.h>
#include <cmath>
#include <iostream>
#include "Point.hpp"

using namespace std;

namespace ariel
{
    Point::Point() : _x(0), _y(0) {}

    Point::Point(double _x, double _y) : _x(_x), _y(_y) {}

    bool Point::operator==(const Point &other) const
    {
        return (_x == other.getX() && _y == other.getY());
    }

    bool Point::operator!=(const Point &other) const
    {
        return !(*this == other);
    }

    double Point::getX() const
    {
        return _x;
    }

    double Point::getY() const
    {
        return _y;
    }

    //https://www.geeksforgeeks.org/program-calculate-distance-two-points/
    double Point::distance(const Point &point) const
    {
        return sqrt(pow(point._x - _x, 2) + pow(point._y - _y, 2));
    }

    string Point::print() const
    {
        string output = "(" + to_string(_x) + "," + to_string(_y) + ")";

        return output;
    }

    // https://math.stackexchange.com/questions/175896/finding-a-point-along-a-line-a-certain-distance-away-from-another-point
    Point Point::moveTowards(Point source, Point destination, double distance)
    {
        if (distance < 0)
            throw invalid_argument("Dinstance negative");
        if (distance == 0)
            return source;
        else if (distance >= source.distance(destination))
            return destination;
        else
        {
            double ratio_dist = distance / source.distance(destination);
            return Point((1 - ratio_dist) * source.getX() + (ratio_dist)*destination.getX(), (1 - ratio_dist) * source.getY() + (ratio_dist)*destination.getY());
        }
    }

}
