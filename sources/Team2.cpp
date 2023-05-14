
#include "Team2.hpp"

namespace ariel
{

    void Team2::add(Character *player)
    {
        if (!player->getInTeam() && player->isAlive() && getTeam().size() < 11)
        {
            getTeam().push_back(player);
            player->setInTeam(true);
        }
        else
        {
            throw runtime_error("Can't add this player");
        }
    }
}