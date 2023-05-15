#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Team.hpp"

namespace ariel
{
    class Team2 : public Team
    {
    protected:
        vector<Character *> _team2;

    public:
        Team2(Character *leader) : Team(leader)
        {
            add(leader);
        }

        ~Team2()
        {
            for (auto fighter : _team2)
            {
                delete fighter;
            }
            _team2.clear();
        }

        void add(Character *player) override
        {

            if (!player->getInTeam() && player->isAlive() && _team2.size() < 11)
            {
                _team2.push_back(player);
                player->setInTeam(true);
            }
            else
            {
                throw runtime_error("Can't add this player");
            }
        }

        int stillAlive() const override
        {
            int counter = 0;

            for (auto fighter : this->_team2)
                if (fighter->isAlive())
                    counter++;
            return counter;
        }

        // Add any additional member functions or overrides as needed for Team2
    };
} // namespace ariel

#endif