#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP

#include "Ninja.hpp"

namespace ariel
{

    class YoungNinja : public Ninja
    {
    public:
        YoungNinja(const string &_name, const Point &_location) : Ninja(_name, _location, 100, 14) {}
    };
}

#endif