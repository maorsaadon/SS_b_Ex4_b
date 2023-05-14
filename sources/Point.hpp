#ifndef POINT_HPP
#define POINT_HPP
#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include <limits>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

namespace ariel
{
    class Point
    {
    private:
        double _x;
        double _y;

    public:
        Point();

        Point(double point_x, double point_y);

        double getPointX() const;

        double getPointY() const;

        bool operator==(const Point &other) const;

        bool operator!=(const Point &other) const;

        double distance(const Point &point) const;

        void print() const;

        static Point moveTowards(Point source, Point destanation, double distance);
    };
};

#endif