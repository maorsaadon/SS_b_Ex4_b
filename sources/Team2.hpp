#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Team.hpp"

namespace ariel
{

    class Team2 : public Team
    {
    public:
        using Team::Team; // Inherit constructors from the base class

        void add(Character *player) override;

    };

} // namespace ariel

#endif
