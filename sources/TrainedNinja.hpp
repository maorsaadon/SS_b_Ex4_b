#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP

#include "Ninja.hpp"

namespace ariel
{

    class TrainedNinja : public Ninja
    {

    public:
        TrainedNinja(const string &name, const Point &location);
        
        // TrainedNinja(const TrainedNinja &other);

        // TrainedNinja(TrainedNinja &&other) noexcept;

        // TrainedNinja &operator=(const TrainedNinja &other);

        // TrainedNinja &operator=(TrainedNinja &&other) noexcept;

        // ~TrainedNinja() = default;
    };
}

#endif