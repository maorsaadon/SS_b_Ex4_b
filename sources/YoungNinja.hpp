#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP

#include "Ninja.hpp"

namespace ariel
{

    class YoungNinja : public Ninja
    {

    public:
        YoungNinja(const string &name, const Point &location);

        // YoungNinja(const YoungNinja &other);

        // YoungNinja(YoungNinja &&other) noexcept;

        // YoungNinja &operator=(const YoungNinja &other);

        // YoungNinja &operator=(YoungNinja &&other) noexcept;

        // ~YoungNinja() = default;
    };
}

#endif