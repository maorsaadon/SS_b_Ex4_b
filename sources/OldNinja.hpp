#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP

#include "Ninja.hpp"

namespace ariel
{

    class OldNinja : public Ninja
    {
    public:
        OldNinja(const string &_name, const Point &_location);
        
        // OldNinja(const OldNinja &other);

        // OldNinja(OldNinja &&other) noexcept;

        // OldNinja &operator=(const OldNinja &other) override;

        // OldNinja &operator=(OldNinja &&other) noexcept override;

        // ~OldNinja() = default;
    };
}

#endif