#ifndef SMARTTEAM_H
#define SMARTTEAM_H

#include "Team.hpp" // Include the base Team class

class SmartTeam : public Team
{
public:
    // Constructor
    SmartTeam(Character *teamLeader) : Team(teamLeader) {}

    // Override the attack() function
    void attack(Team *enemy) override
    {
        if (enemy == nullptr){
            throw invalid_argument("Enemy is nullptr");
        }
        if (stillAlive() == 0 || enemy->stillAlive() == 0){
            throw runtime_error("Game over");
        }

        // Find the closest enemy character
        Character *closestEnemy = findClosestLivingMember(enemy->getTeam(), getLeader()->getLocation());

        // Attack the closest enemy character with all available characters in the team
        for (auto* fighter : getTeam())
        {
            if (fighter != nullptr && fighter->isAlive())
            {
                if (closestEnemy != nullptr && closestEnemy->isAlive())
                {
                    fighter->attack(closestEnemy);
                }
                else
                {
                    // If the closest enemy is not valid, find a new closest enemy and attack
                    closestEnemy = findClosestLivingMember(enemy->getTeam(), getLeader()->getLocation());
                    if (closestEnemy != nullptr && closestEnemy->isAlive())
                    {
                        fighter->attack(closestEnemy);
                    }
                }
            }
        }
    }

    // Add any additional member variables and functions specific to the smart algorithm
};

#endif
