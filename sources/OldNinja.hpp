#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP

#include "Ninja.hpp"

namespace ariel
{

    class OldNinja : public Ninja
    {
    public:
        OldNinja(const string &_name, const Point &_location) : Ninja(_name, _location, 150, 8) {}
    };
}

#endif