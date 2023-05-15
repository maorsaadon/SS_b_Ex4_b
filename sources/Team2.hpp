#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Team.hpp"

namespace ariel
{
    class Team2 : public Team
    {
    public:
        Team2(Character *_teamLeader) : Team(_teamLeader)
        {
        }

        void add(Character *player) override
        {

            if (player == nullptr || !player->isAlive() || player->getInTeam() || _team.size() >= 10)
                throw runtime_error("Can't add this player");
            else
            {
                _team.insert(_team.begin(), player);
                player->setInTeam(true);
            }
        }
    };
}

#endif