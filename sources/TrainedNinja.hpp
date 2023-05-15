#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP

#include "Ninja.hpp"

namespace ariel
{

    class TrainedNinja : public Ninja
    {

    public:
        TrainedNinja(const string &_name, const Point &_location) : Ninja(_name, _location, 120, 12){}
    };
}

#endif