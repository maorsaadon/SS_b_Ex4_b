#include <stdio.h>
#include <cmath>
#include <iostream>
#include "Point.hpp"

using namespace std;

namespace ariel
{
    Point::Point() : _x(0), _y(0) {}

    Point::Point(double _x, double _y) : _x(_x), _y(_y) {}

    bool Point::operator==(const Point &other) const{
        return (_x == other.getPointX() && _y == other.getPointY());
    }

    bool Point::operator!=(const Point &other) const{
        return !(_x == other.getPointX() && _y == other.getPointY());
    }
    
    double Point::getPointX() const
    {
        return _x;
    }

    double Point::getPointY() const
    {
        return _y;
    }

    double Point::distance(const Point &point) const
    {
        return sqrt(pow(point._x - _x, 2) + pow(point._y - _y, 2));
    }

    void Point::print() const
    {
        cout << "(" << _x << "," << _y << ")" << endl;
    }

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
            return Point((1 - ratio_dist) * source.getPointX() + (ratio_dist)*destination.getPointX(), (1 - ratio_dist) * source.getPointY() + (ratio_dist)*destination.getPointY());
        }
    }

}
